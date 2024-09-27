#include <stdio.h>

int isPrime();

int main(){
   int a;
   printf("Enter a number: ");
   scanf("%d",&a);
   if (isPrime(a)==1) printf("%d is prime number",a);
   else printf("%d is not a prime number",a);
   return 0;
}

int isPrime(int x){
   int i, flag = 0;
   if(x <= 1){
      printf("%d is not a prime number.\n", x);
   } else{
      for(i = 2; i <= x-1; i++){
         if(x % i == 0){
            flag = 1;
            break;
         }
      }
      if(flag == 0){
         return 1;
      }
      else{
         return 0;
      }
   }
}