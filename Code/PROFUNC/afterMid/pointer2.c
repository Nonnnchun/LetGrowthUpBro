#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

/* NOTE : เทียบตัวหน้าหลัง */
int main(){
   char str[50];
   char *start, *end;
   printf("Enter a string: ");
   scanf("%s", str);

   start = str/* str[0] = 0 */;
   end = str + strlen(str) - 1; /* str[0] + str[50] - str[49] = end = 49 */

   while (start < end){
      if (*start != *end){
         printf("Not Palindrome\n");
         return 0;
      }
      start++;
      end--;
   }
   printf("Palindrome\n");
   return 0;
}
