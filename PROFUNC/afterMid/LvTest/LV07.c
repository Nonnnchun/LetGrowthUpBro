/* 
#include <stdio.h>
#include <math.h>

typedef struct{
   double x, y, z;
}point;

double distance(point p1, point p2){
   return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

int main(){
   point points[5];

   for (int i = 0; i < 5; i++){
      printf("Enter %d point (x, y, z): ", i + 1);
      scanf("%lf %lf %lf", &points[i].x, &points[i].y, &points[i].z);
   }

   printf("\nPoint entered :\n");
   for (int i = 0; i < 5; i++){
      printf("Point %d --> (%.1f, %.1f, %.1f)\n", i + 1, points[i].x, points[i].y, points[i].z);
   }

   point points[5] = {{0, 0, 0},
                      {1, 1, 1},
                      {2, 2, 2},
                      {5, 5, 5},
                      {3, 3, 3}};
   
   double dist = 0;
   double maxDistance=0;
   int point1=0, point2=0;

   for(int i = 0; i<5; i++){
      for(int j = i+1; j<5; j++){
         dist = distance(points[i], points[j]);
         if(dist > maxDistance){
            maxDistance = dist;
            point1 = i;
            point2 = j;
         }
      }
   }
   printf("Point 1: (%.1f, %.1f, %.1f)\n", points[point1].x, points[point1].y, points[point1].z);
   printf("Point 2: (%.1f, %.1f, %.1f)\n", points[point2].x, points[point2].y, points[point2].z);
   printf("Distance: %.3f\n", maxDistance);
   return 0;
} 
*/


#include <stdio.h>
#include <string.h>

int main(){
   char string[100]; // "3582435798325"
   printf("Enter a string (number): ");
   scanf("%[^\n]", string);
   int n = strlen(string);
   int maxSum = 0;
   int currentSum = 0;
   int start, end, temp;

   for(int i=0; i<n; i++){
      if(i==0||string[i]>=string[i-1]){
         currentSum = currentSum + (string[i] - '0');
      } else {
         if(currentSum>maxSum){
            maxSum = currentSum;
            start = temp;
            end = i-1;
         }
         currentSum = string[i] - '0';
         temp = i;
      }
   }
   if (currentSum>maxSum){
      maxSum = currentSum;
      start = temp;
      end = n-1;
   }

   printf("Maximum sum : ");
   for(int i = start; i<= end; i++){
      if(i == start){
         printf("%d ",string[i]- '0');
      } else if (i != end){
         printf("+ %d ",string[i]- '0');
      } else {
         printf("+ %d =",string[i]- '0');
      }
   }
   printf(" %d\n", maxSum);
   return 0;
}