#include <string.h>
#include <stdio.h>


int main(){
   char input[100];
   char str[100];
   int index = 0;

   printf("Input string : ");
   fgets(input, 100, stdin);
   for (int i = 0; i < strlen(input); i++){
      if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')){
         str[index] = input[i];
         index++;
      }
   }
   for (int i = 0; i < index; i++){
      if (str[i] == str[index - 1 - i] || str[i] == str[index - 1 - i] + 32 || str[i] == str[index - 1 - i] - 32){
         continue;
      } else {
         printf("Not palindrome\n");
         return 0;
      }
   }
   printf("Palindrome\n");
   return 0;
}