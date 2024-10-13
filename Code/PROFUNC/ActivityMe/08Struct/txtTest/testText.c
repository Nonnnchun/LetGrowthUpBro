#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1

int main(){
   FILE *file;
   file = fopen("mytestfileA.txt","a");
   fprintf(file,"%d %d %d\n",100 ,200 ,500);
   fclose(file);
   return 0;
}