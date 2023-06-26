package Assign3;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;
public class Main {
    // a class that represents a memory partition
    static class Partition {
        String name;
        int size;
        Partition(String name, int size) {
            this.name = name;
            this.size = size;
        }
    }

    // a class that represents a process
    static class Process {
        String name;
        int size;

        Process(String name, int size) {
            this.name = name;
            this.size = size;
        }
    }

    // a class that allocates processes to memory using different policies
    static class MemoryAllocator {
        // allocate a process to memory using the First-Fit policy
        public void allocateFirstFit(Memory memory, Process process) {
    for (int i = 0; i < memory.partitions.size(); i++) {
        Partition partition = memory.partitions.get(i);
        if (partition.size >= process.size) {
            int remainingSize = partition.size - process.size;
            partition.size = process.size;
            System.out.println("Partition " + i + " (" + partition.size + " KB) => " + process.name);
            if (remainingSize > 0) {
                // create a new partition with the remaining size and add it after the allocated partition
                Partition remainingPartition = new Partition("p" + (memory.partitions.size() + 1), remainingSize);
                memory.partitions.add(i + 1, remainingPartition);
            }
            return;
        }
    }
    System.out.println("Cannot allocate process " + process.name + ": not enough memory");
}


        // allocate a process to memory using the Best-Fit policy
        public void allocateBestFit(Memory memory, Process process) {
            Partition bestFit = null;
            int bestFitIndex = -1;
            for (int i = 0; i < memory.partitions.size(); i++) {
                Partition partition = memory.partitions.get(i);
                if (partition.size >= process.size && (bestFit == null || partition.size < bestFit.size)) {
                    bestFit = partition;
                    bestFitIndex = i;
                }
            }
            if (bestFit != null) {
                bestFit.size -= process.size;
                System.out.println("Partition " + bestFitIndex + " (" + bestFit.size + " KB) => " + process.name);
            } else {
                System.out.println("Cannot allocate process " + process.name + ": not enough memory");
            }
        }

        // allocate a process to memory using the Worst-Fit policy
        public void allocateWorstFit(Memory memory, Process process) {
            Partition worstFit = null;
            int worstFitIndex = -1;
            for (int i = 0; i < memory.partitions.size(); i++) {
                Partition partition = memory.partitions.get(i);
                if (partition.size >= process.size && (worstFit == null || partition.size > worstFit.size)) {
                    worstFit = partition;
                    worstFitIndex = i;
                }
            }
            if (worstFit != null) {
                worstFit.size -= process.size;
                System.out.println("Partition " + worstFitIndex + " (" + worstFit.size + " KB) => " + process.name);
            } else {
                System.out.println("Cannot allocate process " + process.name + ": not enough memory");
            }
        }

        // compact the memory by moving processes to the beginning and merging empty partitions at the end
        public void compact(Memory memory) {
            List<Partition> nonEmptyPartitions = new ArrayList<>();
            List<Partition> emptyPartitions = new ArrayList<>();
            for (Partition partition : memory.partitions) {
                if (partition.size > 0) {
                    nonEmptyPartitions.add(partition);
                } else {
                    emptyPartitions.add(partition);
                }
            }
            nonEmptyPartitions.addAll(emptyPartitions);
            memory.partitions = nonEmptyPartitions;
        }
    }

    // a class that represents a memory with a list of partitions
    static class Memory {
        List<Partition> partitions;

        Memory(int numPartitions, String[] partitionNames, int[] partitionSizes) {
            partitions = new ArrayList<>();
            for (int i = 0; i < numPartitions; i++) {
                partitions.add(new Partition(partitionNames[i], partitionSizes[i]));
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // read the number of partitions
        System.out.print("Enter the number of partitions: ");
        int numPartitions = scanner.nextInt();

        // read the names and sizes of the partitions
        String[] partitionNames = new String[numPartitions];
        int[] partitionSizes = new int[numPartitions];
        for (int i = 0; i < numPartitions; i++) {
            System.out.print("Enter the name of partition " + i + ": ");
            partitionNames[i] = scanner.next();
            System.out.print("Enter the size of partition " + i + " (in KB): ");
            partitionSizes[i] = scanner.nextInt();
        }

        // create a memory with the given partitions
        Memory memory = new Memory(numPartitions, partitionNames, partitionSizes);

        // create a memory allocator
        MemoryAllocator allocator = new MemoryAllocator();

        // read the number of processes
        System.out.print("Enter the number of processes: ");
        int numProcesses = scanner.nextInt();

        // read the names and sizes of the processes
        String[] processNames = new String[numProcesses];
        int[] processSizes = new int[numProcesses];
        for (int i = 0; i < numProcesses; i++) {
            System.out.print("Enter the name of process " + i + ": ");
            processNames[i] = scanner.next();
            System.out.print("Enter the size of process " + i + " (in KB): ");
            processSizes[i] = scanner.nextInt();
        }

        // create a list of processes
        List<Process> processes = new ArrayList<>();
        for (int i = 0; i < numProcesses; i++) {
            processes.add(new Process(processNames[i], processSizes[i]));
        }

        // read the memory allocation policy
        System.out.print("Enter the memory allocation policy (1 = First-Fit, 2 = Best-Fit, 3 = Worst-Fit): ");
        int policy = scanner.nextInt();

        // allocate the processes to memory using the chosen policy
        switch (policy) {
            case 1 -> {
                for (Process process : processes) {
                    allocator.allocateFirstFit(memory, process);
                }
            }
            case 2 -> {
                for (Process process : processes) {
                    allocator.allocateBestFit(memory, process);
                }
            }
            case 3 -> {
                for (Process process : processes) {
                    allocator.allocateWorstFit(memory, process);
                }
            }
            default -> System.out.println("Invalid policy");
        }

        // print the state of the memory after allocating the processes
        for (int i = 0; i < memory.partitions.size(); i++) {
            Partition partition = memory.partitions.get(i);
            if (partition.size > 0) {
                System.out.println("Partition " + i + " (" + partition.size + " KB) => External fragment");
            }
        }

        // ask the user if they want to compact the memory
        System.out.print("Do you want to compact the memory? (y/n) ");
        String choice = scanner.next();

        if (choice.equalsIgnoreCase("y")) {
            // compact the memory
            allocator.compact(memory);

            // print the state of the memory after compacting
            for (int i = 0; i < memory.partitions.size(); i++) {
                Partition partition = memory.partitions.get(i);
                if (partition.size > 0) {
                    System.out.println("Partition " + i + " (" + partition.size + " KB) => External fragment");
                }
            }
        }
    }
}