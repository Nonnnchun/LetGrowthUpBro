#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct info{
   int no;
   double lat;
   double lon;
};

void printInfo(struct info rec){
   printf("no : %d\t latitude : %f\t longitude :%f\n", rec.no, rec.lat, rec.lon);
}

void readCSV(){
   FILE *fpr = fopen("C:\\Code\\PROFUNC\\Assignment\\1\\latlonfile.csv", "r");
   char line[100];
   struct info rec;
   char *token;
   char *delim = ",";

   if (fpr == NULL) {
      printf("Error opening file\n");
      return;
   }

   while(fgets(line, sizeof(line), fpr) != NULL){
      line[strcspn(line, "\n")] = 0;
      token = strtok(line, delim);
      int col = 1;
      while(token != NULL){
         switch(col){
            case 1:
               rec.no = atoi(token);
               break;
            case 2:
               rec.lat = atof(token);
               break;
            case 3:
               rec.lon = atof(token);
               break;
         }
         col++;
         token = strtok(NULL, delim);
      }
      printInfo(rec);
      printf("\n");
   }
   fclose(fpr);
}

int main(){
   readCSV();
   return 0;
}