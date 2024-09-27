// SECTION - read file , calculate , write file

#include <stdio.h>
#include <string.h>
int calculator(char *x){
   int result = 0, temp = 0;
   char op = '+';
   for (int i = 0; i < strlen(x); i++){
      if (x[i] >= '0' && x[i] <= '9'){
         temp = temp * 10 + (x[i] - '0');
      } else if (x[i] == '+' || x[i] == '-'){
         if (op == '+'){
            result += temp;
            temp = 0;
         } else if (op == '-'){
            result -= temp;
            temp = 0;
         }
      }
   }
   if (op == '+'){
      result += temp;
   } else if (op == '-'){
      result -= temp;
   }
   return result;
}

int main(){
   FILE *fpr, *fpw;
   char line[100];

   fpr = fopen("calculator_hard.txt", "r");
   fpw = fopen("calculator_hard_67011509.txt", "w");

   if (fpr == NULL || fpw == NULL){
      printf("Could not open file.\n");
      return 1;
   }

   while (fgets(line, sizeof(line), fpr) != NULL){
      line[strcspn(line, "\n")] = 0; // NOTE : ลบช่องว่างหรือ newline ที่ท้ายบรรทัดถ้ามี
      int result = calculator(line);
      fprintf(fpw, "%s = %d\n", line, result);
      printf("%s = %d\n", line, result);
   }

   fclose(fpr);
   fclose(fpw);

   return 0;
}
