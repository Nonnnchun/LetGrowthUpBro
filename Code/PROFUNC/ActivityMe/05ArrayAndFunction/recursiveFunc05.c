#include <stdio.h>
#include <string.h>
/* 
int fac(int x){
   if (x == 0){
      return 1;
   } else{
      return x * fac(x-1);
   }
}

int main(){
   int n;
   printf("Enter a positive integer: ");
   scanf("%d", &n);
   printf("%d! = %d\n", n, fac(n));
   return 0;
}
 */

//--------------------------------------------------------------------------------------------------------------------

/* int fibo(int);
int main(){
   int n;
   printf("Enter fibonacci n : ");
   scanf("%d", &n);
   printf("The pattern is : ");
   if (n>0){
      for(int i = 1; i<=n; i++){
         printf("%d ", fibo(i));
         if(i>=n) break;
         else;
      }
   } else printf("Input positive number");
   
   printf("\n");

   if(n>0 && n==1){
      printf("%dst of fibonacci is = %d ",n ,fibo(n));
   } else if (n>0 && n==2){
      printf("%dnd of fibonacci is = %d ",n ,fibo(n));
   } else if (n>0 && n ==3){
      printf("%drd of fibonacci is = %d ",n ,fibo(n));
   } else if (n>0 && n>3){
      printf("%dth of fibonacci is = %d ",n ,fibo(n));
   } else;
   return 0;
}

int fibo(int x){
   if (x == 1){
      return 0;
   } else if (x == 2){
      return 1;
   } else{
      return (fibo(x-1) + fibo(x-2));
   }
} */

//--------------------------------------------------------------------------------------------------------------------

/* 
int GCD(int, int);
int main(){
   int a,b;
   printf("Enter two numbers: ");
   scanf("%d %d", &a,&b);
   printf("gcd(%d, %d) = %d\n",a,b,GCD(a,b));
}

int GCD(int a, int b){
   if (a == 0){
      return b;
   } else {
      return GCD(b % a, a);
   }
} */

//--------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
int palindrome(char *str, int start, int end){
   if (start >= end){ // SECTION : check all characters in string 
      return 1;
   } if (str[start] != str[end]){ // SECTION : palindrome check
      return 0;
   } else{ //SECTION : str[start]== str[end]
      return 1;
   }
   return palindrome(str, start + 1, end - 1); // SECTION : recursive call --> str, start++, end--
}

int main(){
   //NOTE : Input
   char str[100];
   printf("Enter a string: ");
   scanf("%[^\n]", str);

   // NOTE : Set value
   int start = 0;
   int end = strlen(str) - 1;

   //NOTE : Check palindrome form return 0 or 1
   if (palindrome(str,start,end) == 1){
      printf("'%s' is a palindrome.\n", str);
   } else if (palindrome(str, start, end) == 0){
      printf("'%s' is not a palindrome.\n", str);
   } else printf("Invalid input.\n");
   return 0;
}