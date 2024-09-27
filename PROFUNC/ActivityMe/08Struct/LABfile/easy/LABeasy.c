// SECTION - read file , calculate , write file

#include <stdio.h>

int main(){
   FILE *fpr;
   fpr = fopen("calculator_easy.txt", "r");

   FILE *fpw;
   fpw = fopen("calculator_easy_67011509.txt", "w");

   while(!feof(fpr)){
      if (fpr == NULL){
         printf("Could not open file.\n");
         return 1;
      } else{
         int num1, num2, sum;
         char op;
         fscanf(fpr, "%d %c %d", &num1, &op, &num2);
         if (op == '+'){
            sum = num1 + num2;
         } else if (op == '-'){
            sum = num1 - num2;
         } else {
            printf("Invalid operator.\n");
            continue;
         }
         printf("%d %c %d = %d\n", num1, op, num2, sum);
         fprintf(fpw, "%d %c %d = %d\n", num1, op, num2, sum);
      }
   }
   fclose(fpw);
   fclose(fpr);
   return 0;
}