#include <stdio.h>
// draw M 
/* 
   *        *
   * *    * *
   *  *  *  *
   *    *   *
 */

/* int main(){
   int n;
   scanf("%d",&n);
   for(int i = n-1; i >= 0; i--){
      for(int j = 0; j < (2*n)-1; j++){
         if(j == 0 || j == (2*n)-2){
            printf("* ");
         } else if (j == n-i-1 || j== n+i-1){
            printf("* ");
         } else {
            printf("  ");
         }
      }
      printf("\n");
   }
} */
//NOTE : LV-4

int main(){
   /* (Data Clustering) */
   int n, m;
   scanf("%d", &n);
   scanf("%d", &m);
   int array1[n][m];
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         scanf("%d", &array1[i][j]);
      }
   }
   int array2[n][m];
   for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++)
      {
         scanf("%d", &array2[i][j]);
      }
   }
}