#include<stdio.h>


int main(){
    int n = 121 , reversedInteger = 0 /* NOTE : แก้จาก reversedInteger = 1 */, remainder, originalInteger;
    
    originalInteger = n;
    // reversed integer is stored in variable (#1)
    while( n!=0 )
    {
        remainder = n%10;
        reversedInteger = reversedInteger*10 + remainder;
        n /= 10;  //(#2)
    }
    // palindrome if originalInteger and reversedInteger are equal (#3)
    if (originalInteger == reversedInteger)
        printf("%d is a palindrome.", originalInteger);
    else
        printf("%d is not a palindrome.", originalInteger);
    return 0;
}