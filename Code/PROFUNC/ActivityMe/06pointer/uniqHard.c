#include <stdio.h>

void uniqA(char *x, char *y){
   char *p = x;
   int index = 0;
   while (*p != '\0'){ // NOTE : first pointer
      char c = *p;
      y[index] = c;
      index++;
      while (*(p + 1) == c){ // NOTE : second pointer
         p++;
      }
      p++;
   } y[index] = '\0';
}

void uniqB(char *a, char *b){
   char *p = a;
   int index = 0;
   while (*p != '\0'){ // NOTE : first pointer
      char c = *p;
      b[index] = c;
      index++;
      while (*(p + 1) == c){ // NOTE : second pointer
         p++;
      }
      p++;
   }
   b[index] = '\0';
}

int stringsEqual(char *a, char *b){
   while (*a != '\0' && *b != '\0'){
      if (*a != *b){
         return 0;
      } else ;
      a++;
      b++;
   } return 1;
}

int main(){
   char resultA[100], resultB[100];

   char a[100];
   printf("Enter a string: ");
   scanf("%[^\n]", a);
   uniqA(a,resultA);
   printf("uniqA = %s\n", resultA);

   getchar(); // find the newline('\n') after first input // NOTE : string or char 2value++ much have --> reset input

   char b[100];
   printf("Enter a string: ");
   scanf("%[^\n]", b);
   uniqB(b,resultB);
   printf("uniqB = %s\n", resultB);


   if (stringsEqual(resultA, resultB)){
      printf("Both strings are equal\n");
   } else{
      printf("Both strings are not equal\n");
   }
   return 0;
}