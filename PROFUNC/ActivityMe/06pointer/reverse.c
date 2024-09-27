#include <stdio.h>
#include <string.h> // NOTE : strrev(str)

void reverse(void){
   char str[100], *r = str;
   printf("Enter strings : ");
   scanf("%[^\n]", str);
   printf("Your strings = %s\n", r);
   while (*r != '\0'){
      r++;
   }
   r--;
   printf("Last strings = %c\nReverse string = ", *r);
   while (r >= str){
      printf("%c", *r);
      r--;
   }
   printf("\n----------------------------------------------------------------\n");
}

int main(){
   reverse();
   return 0;
}