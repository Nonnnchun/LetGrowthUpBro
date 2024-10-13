#include <stdio.h>
#include <string.h>

void changeChar(){
   char str[100],*p;
   printf("Enter a string: ");
   scanf("%[^\n]", str);
   p = str;
   while(*p != '\0'){
      if(*p >= 'a' && *p <= 'z'){
         printf("%c", *p-32);
      }
      else if (*p >= 'A' && *p <= 'Z'){
         printf("%c", *p+32);
      } else ;
      p++;
   };
}

int main(){
   changeChar();
   return 0;
}