#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1

int main(){
   FILE *file;
   int a, b, c, suma=0, sumb=0, sumc=0;
   file = fopen("mytestfile.txt", "r");
   while(!feof(file)){//NOTE : EOF = End-of-file
   fscanf(file, "%d %d %d", &a, &b, &c);
   suma += a;
   sumb += b;
   sumc += c;
   }
   printf("%d %d %d\n", a, b, c);
   printf("%d %d %d\n", suma, sumb, sumc);
   fclose(file);
   return 0;
}