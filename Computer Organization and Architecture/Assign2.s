# gcc -O3 -o myfile.exe myfile.s

.intel_syntax noprefix

.section .data        # memory variables

input: .asciz "%d"    # input
output: .asciz "sum of series is: %f\n"     # output

n: .int 0             # input variable
s: .double 0.0        # summation variable
one: .double 1.0      # variable holding 1
r: .double 1.0        # variable holding 1


.section .text        # instructions
.globl _main          # make _main global

_main:                # main
   push OFFSET n      # push to stack the second parameter to scanf (top of stack)
   push OFFSET input  # push to stack the first parameter to scanf
   call _scanf        # call scanf
   add esp, 8         # add 8 to esp 
   
   mov ecx, n         # assign ecx with n
loop1:
   # the next 5 instructions increase s by r + 1/r^2

   fld qword ptr one            # push 1 to the floating point stack
   
   fdiv qword ptr r             # pop the floating point stack top (1), divide it over r and push the result (1/r)
   fdiv qword ptr r             # pop the floating point stack top (r), divide it over r and push the result (1/r^2)
   fadd qword ptr r             # pop the floating point stack top (1/r^2), add it to r and push the result (r+ 1/r^2)
   fadd qword ptr s             # pop the floating point stack top (r+ 1/r^2), add it to s, and push the result (s+(r+ 1/r^2))
   fstp qword ptr s             # pop the floating point stack top (s+(r+ 1/r^2)) into the memory variable s

   # the next 3 instructions increment r by 1   
   fld qword ptr r              # push 1 to the floating point stack
   fadd qword ptr one           # pop the floating point stack top (1), add it to r and push the result (r+1)
   fstp qword ptr r             # pop the floating point stack top (r+1) into the memory variable r

   loop loop1         # ecx -=1 , then goto loop1 only if ecx is not zero
   
   push [s+4]         # push to stack the high 32-bits of the second parameter to printf (the double at label s)
   push s             # push to stack the low 32-bits of the second parameter to printf (the double at label s)
   push OFFSET output # push to stack the first parameter to printf
   call _printf       # call printf
   add esp, 12        # pop the two parameters

   ret                # end the main function
