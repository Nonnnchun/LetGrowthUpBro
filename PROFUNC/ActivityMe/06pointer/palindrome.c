#include <stdio.h>
#include <string.h>

void palindrome(){
   char str[100], *p;
   printf("Enter your string : ");
   scanf("%[^\n]", str);
   p = str;
   while (*p != '\0'){
      p++;
   } p--;
   int flag;
   for (int i = 0; i < strlen(str); i++){
      if (str[i] != *p){
         flag = 1;
         break;
      } else
         flag = 0;
      p--;
   }
   if (flag == 0){
      printf("Palindrome");
   } else{
      printf("Not Palindrome");
   }
   printf("\n----------------------------------------------------------------\nYour string is : %s", str);
}

int main(){
   palindrome();
   return 0;
}