#include <stdio.h>

void square(int x){
   for(int i = 0; i<x; i++){
         printf("* ");
   }
   printf("\n");

   for(int i = 0; i<x-2; i++){
      for(int j = 0; j<x; j++){
         if(j==0 || j==x-1){
            printf("* ");
         } else {printf("  ");}
      }
      printf("\n");
   }

   for(int i=0; i<x; i++){
         printf("* ");
   }
}

int main(){
   int n;
   printf("Enter a positive integer: ");
   scanf("%d", &n);
   while(n>1){
      square(n);
      printf("\n");
      printf("Enter a positive integer: ");
      scanf("%d",&n);
   } printf("Invalid value of input");
   return 0;
}