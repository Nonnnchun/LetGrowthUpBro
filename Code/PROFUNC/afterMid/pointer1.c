#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h> //NOTE : isalpah islower isupper toupper tolower

int main(){
   char *p, str[50];
   p = str;
   scanf("%s", str);

   while (*p != '\0'){
      if (isalpha(*p)) {
         if (islower(*p)){
            printf("%c", toupper(*p));
         } else if (isupper(*p)){
            printf("%c", tolower(*p));
         }
      }
      p++;
   }

   printf("\n");

   system("pause");

   return 0;
}