#include <stdio.h>

void swaP(int *x, int *y){
   int a = *x;
   *x = *y;
   *y = a;
}

int main(){
   int a, b;
   scanf("%d %d", &a, &b);
   printf("Non-swap: (%d, %d)\n", a, b);
   swaP(&a, &b);
   printf("swapped: (%d, %d)\n", a, b);
   return 0;
}