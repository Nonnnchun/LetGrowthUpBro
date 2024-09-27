#include <stdio.h>

int max(int x, int y, int z){ // return (x > y && x > z)? x : (y > z)? y : z;
   return (x > y && x > z) ? x 
   : (y > z) ? y 
   : z;
   /*
   int result;
   if (x > y && x > z) {
       result = x;
   } else {
       if (y > z) {
           result = y;
       } else {
           result = z;
       }
   }*/
}

int min(int x, int y, int z){
   return x < y ? x : y < z ? y : z;
   /*
   int result;
   if (x < y && x < z) {
      result = x;
   } else {
      if (y < z) {
         result = y;
      } else {
         result = z;
      }
   }*/
}

int sum(int x, int y){
   return x+y;
}

int main(){
   int a,b,c;
   scanf("%d %d %d",&a,&b,&c);
   printf("Sum of max and min is : %d\n", sum(max(a,b,c),min(a,b,c)));
   return 0;
}