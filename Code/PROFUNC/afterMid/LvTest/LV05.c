#include <stdio.h>

int series10(int x, int y){
   for(int n = 0; n < 10; n++){
      printf("%d ", x+(y*n));
   }
}
int main(){
   int a, r;
   printf("Input :");
   scanf("%d %d", &a, &r);
   printf("Xn = %d + %d * n\nOutput : ", a, r);
   series10(a, r);
   return 0;
} //NOTE - L2
/* 
#include <stdio.h>
#include <string.h>

int main(){
   char str[100];
   printf("Input string : ");
   gets(str);
   int count[256] = {0};
   for(int i = 0; i < strlen(str); i++){
      if(str[i] >= 'A' && str[i] <= 'Z'){
         count[str[i] - 'A']++;
      }
   }
   printf("Character count \n");
   for(int i = 0; i < 256; i++){
      if(count[i]!= 0){
         printf("%c : %d\n", i + 'A', count[i]);
      }
   }

   return 0;
} */