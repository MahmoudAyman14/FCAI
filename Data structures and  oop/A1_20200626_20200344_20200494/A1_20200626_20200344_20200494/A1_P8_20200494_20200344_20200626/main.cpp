#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int BinarySearch(int MyArray[],int x,int y,int z)
{
    if (y <= x )

        return ( z > MyArray[x] )? (x+1): x;

    int middle = (x + y)/2;

    if(z == MyArray[middle])
        return middle;
    if (z > MyArray[middle])
        return BinarySearch(MyArray,middle+1,y,z);


    return BinarySearch(MyArray,x,middle-1,z);



}
void InsertionSort(int arr[], int n)
{
    int  temp;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
       int j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
void BianryInsertionSort(int arr[], int n)
{
    int temp, position;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
       int j = i - 1;

        position = BinarySearch(arr, 0, j, temp);

        while (j >= position) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}
int getrandom(int Max){
    int result = 0;
    result = rand()% Max +1;
    return result;
}

void print(double ArrSize[10],double ArrBinInsertion[10],double ArrInsertion[10]){

    cout<<"Size"<<setw(16)<<"BinaryInsertion"<<setw(10)<<"Insertion"<<endl;
    for(int i =0;i<10;++i){
        cout<<ArrSize[i]<<setw(10)<<ArrBinInsertion[i]<<"s"<<setw(10)<<ArrInsertion[i]<<"s"<<endl;
    }

}
int main()
{
    double ArrLength[10],ArrBinInsertion[10],ArrInsertion[10];
    int pos = 0;
    srand(time(0));
    for (int length=10000 ; length<=55000;length +=5000){
        ArrLength[pos]=length;

        int arr[length],arr2[length];
        for (int i=0; i<length ;++i) 
        arr[i]=arr2[i]=getrandom(10000);

        double start = clock();
        BianryInsertionSort(arr, length);
        double finish = clock();
        double elapsed = difftime(finish,start)/CLOCKS_PER_SEC;
        ArrBinInsertion[pos]=elapsed;

        for (int i=0; i<length ;++i)  
        arr[i]=getrandom(10000);
        start =clock();
        InsertionSort(arr2, length);
        finish = clock();
        elapsed = difftime(finish,start)/CLOCKS_PER_SEC;
        ArrInsertion[pos]=elapsed;
        ++pos;
    }

    cout<<"Comparison between Binary insertion sort and insertion sort!"<<endl<<endl;

    print(ArrLength,ArrBinInsertion,ArrInsertion);


    return 0;
}
