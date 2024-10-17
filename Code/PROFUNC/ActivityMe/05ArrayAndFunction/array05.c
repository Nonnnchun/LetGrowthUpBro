#include <stdio.h>
#include <string.h>

/* int main(){
   
   //input string
   //save value in array
   char string[100];
   printf("Input string : ");
   scanf("%s",string);
   
   //print string(All)
   for (int i = 0; i < strlen(string); i++) {

      // if true (if string[i]) == uppercase characters --> print
      if (string[i] >= 'A' && string[i] <= 'Z'){
         printf("%c",string[i]);
      }
   }
   return 0;
} */

/* int main() {
   //input
   //save value in array
   char a[100];
   char b[100];
   int n;
   printf("How much number do you have? : ");
   scanf("%d",&n);

   scanf("%s", a);
   for(int i=1; i<n; i++){
      scanf("%s", b);
      strcat(a,b);
   }

   //print all values
   for(int i=0; i<strlen(a); i++){
      //printf("%d ", a[i] - '0');
      // check if a[i-1]>a[i] && a[i+1]>a[i] --> print a value
      if (a[i - 1] > a[i] && a[i + 1] > a[i]){
         printf("Between = %c\n", a[i]);
      }
   }
   return 0;
} */

int main(){
   // SECTION : input int & save value in array
   int n;
   printf("How many numbers do you have? : ");
   scanf("%d", &n);

   // NOTE : Details number have can't = 0
   if (n <= 0){
      printf("Invalid number of inputs.\n");
      return 1;
   }

   // NOTE : Details input value
   int numbers[n];
   printf("Enter the numbers: ");
   for (int i = 0; i < n; i++){
      scanf("%d", &numbers[i]);
   }

   // SECTION : print all values and check
   printf("Local minima: ");
   for (int i = 1; i < n - 1; i++){ // NOTE : Details first and last number aren't calculated
      // NOTE : check if a[i-1] > a[i] && a[i+1] > a[i] --> print a value
      if (numbers[i - 1] > numbers[i] && numbers[i + 1] > numbers[i]){
         printf("%d ", numbers[i]);
      }
   }

   printf("\n");
   return 0;
}