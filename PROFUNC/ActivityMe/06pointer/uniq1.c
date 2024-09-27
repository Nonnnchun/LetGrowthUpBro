#include <stdio.h>
#include <string.h>

void uniq(){
   char str[100], *p;
   printf("Enter a string: ");
   scanf("%[^\n]", str);
   p = str;
   for (int i = 0; i < strlen(str); i++){
      if (*(p + i) != *(p + i - 1)){ // NOTE : str[i] != str[i - 1]
         printf("%c", *(p + i));
      }
   }
}

int main(){
   uniq();
   return 0;
}
