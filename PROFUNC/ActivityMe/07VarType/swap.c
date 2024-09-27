#include <stdio.h>

void swap(int *x, int *y){
   int a;
   a = *x;
   *x = *y;
   *y = a;
}

int main(){
   int num1, num2;
   printf("Enter number : ");
   scanf("%d %d", &num1, &num2);
   printf("Before swapped: (%d, %d)\n", num1, num2);
   swap(&num1, &num2);
   printf("After  swapped: (%d, %d)", num1, num2);
   return 0;
}