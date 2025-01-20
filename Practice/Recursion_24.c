/*Write a small C function (no need for main, header files etc.) to print the moves of the well-known
Tower of Hanoi problem using recursion. Assume that the smallest disc is numbered as ‘disc 1’
and the largest is ‘disc n’. Each of the three pegs is represented by a char (datatype): source (‘S’),
destination (‘D’) and temporary (‘T’). Given below are some examples of the moves that you will
print:

Move the disc # 12 from T to D
Move the disc # 4 from S to T.
Now just write the output of your function if it is called with n = 4, where n is the number of
discs.*/


#include <stdio.h>

void TOH(int n,char A,char B,char C){
    if(n>0){
        TOH(n-1,A,C,B);
        printf("Move  disc #%d from %c to %c \n",n,A,C);
        TOH(n-1,B,A,C);
    }
}
int main() {
   TOH(2,'S','T','D');

    return 0;
}