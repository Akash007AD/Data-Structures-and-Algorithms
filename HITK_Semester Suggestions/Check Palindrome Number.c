#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int check(int num){
    int n=0;
    int temp=num;
    while(temp>0){
        n=(n*10)+(temp%10);
        temp=temp/10;
    }
    if(num==n)
        return 1;
    else
        return 0;
}
bool check_palindrome(char* str,int left,int right){
    if(left>=right) return true;
    else if (str[left]==str[right]) return check_palindrome(str,left+1,right-1);
    else return false;
    
}
int main() {
   if(check(121))
        printf("Palindrome\n");
    else
        printf("not Palindrome\n");
    char str[]="MALAYALAMA";
    if(check_palindrome(str,0,strlen(str)-1))
        printf("%s is Palindrome\n",str);
    else
        printf("%s is not Palindrome\n",str);
    
}
