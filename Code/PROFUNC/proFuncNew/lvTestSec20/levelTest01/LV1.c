#include <stdio.h>

int main(){
   int num1,num2;
   printf("Input two number : ");
   scanf("%d %d", &num1, &num2);

   num1 > num2 ? printf("%d", num1) : printf("%d", num2);
}