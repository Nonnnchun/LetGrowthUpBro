#include <stdio.h>

void uniq(){
   char str[100], *p;
   printf("Enter a string: ");
   scanf("%[^\n]", str);
   p = str;
   while (*p != '\0'){ //NOTE : first pointer
      char c = *p;
      printf("%c", *p);
      while (*(p + 1) == c){ //NOTE : second pointer
         p++;
      } p++;
   }
}

int main(){
   uniq();
   return 0;
}
