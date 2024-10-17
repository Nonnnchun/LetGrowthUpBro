#include <stdio.h>
#include <string.h>

int main(){
   char a[100];
   char b[100];
   printf("Keyword: ");
   scanf("%s", a);
   getchar();

   printf("Data: ");
   scanf("%[^\n]", b);
   getchar();

   int count = 0;
   for(int i = 0; i <strlen(b); i++){
      // NOTE : strstr is searches the string haystack for the first occurrence of the substring needle.
      // SECTION - Success: A pointer to the first occurrence of the needle in the haystack is returned. If needle is found within haystack, strstr returns a pointer to the beginning of the first occurrence of needle.
      // SECTION - Failure: If needle is not found within haystack, strstr returns NULL.
      if(strstr(&b[i], a)!= NULL){
         count++;
         i += strlen(a);
      }
      /* else if(b[i] ==' ' && b[i]!= '\0'){
         i++;
      }
      else if(b[i] == '\0'){
         break;
      }
      else{
         i++;
      } */
   }
   printf("Keyword '%s' found %d times in the given data.\n", a, count);
   return 0;
}
