#include <stdio.h>
#include <stdlib.h>

#define rows 6
#define cols 6
#define generations 15

/* ANCHOR - Grid creation */ 
/* REVIEW - Created by int grid --> in main function */
void printGrid(int grid[rows][cols]){
   for (int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
         if (grid[i][j] == 1){
            printf("* ");/* NOTE : live */
            } else {
            printf(". ");/* NOTE : dead */
         }
      }
      printf("\n");
   }
   printf("\n");
}

/*REVIEW - count live */
int countLiveNeighbors(int grid[rows][cols], int x, int y){
   int count = 0;
   for (int i = x - 1; i <= x + 1; i++){ //NOTE : นับรอบเซลล์แกน X
      for (int j = y - 1; j <= y + 1; j++){ //NOTE : นับรอบเซลล์แกน Y
         if ((i == x && j == y) || i < 0 || i >= rows || j < 0 || j >= cols) //FIXME - ถ้าหลุดออกนอก grid ไม่นับ และ เช็คจุดศูนย์กลาง
            continue;
         if (grid[i][j] == 1)
            count++;
      }
   }
   return count;
}

/* ANCHOR - RULES */
void updateGrid(int grid[rows][cols], int newGrid[rows][cols]){
   for (int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
         int liveNeighbors = countLiveNeighbors(grid, i, j);
         // NOTE : 1. If the cell is alive:
         if (grid[i][j] == 1){
            if (liveNeighbors < 2 || liveNeighbors > 3){
               newGrid[i][j] = 0; 
            } else{
               newGrid[i][j] = 1;
            }
         }
         else
         { // NOTE : 2. If the cell is dead:
            if (liveNeighbors == 3){
               newGrid[i][j] = 1;
            } else {
               newGrid[i][j] = 0;
            }
         }
      }
   }
}

int main(){
   int grid[rows][cols] = {{0, 1, 0, 0, 0},
                           {0, 0, 1, 1, 0},
                           {0, 1, 1, 0, 0},
                           {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0}};
   
   int newGrid[rows][cols];

   /*SECTION : #define generations 15 */
   for (int gen = 0; gen < generations; gen++){
      printf("Generation %d :\n", gen);
      printGrid(grid);
      updateGrid(grid, newGrid);

      /*STUB : newGrid --> grid */
      for (int i = 0; i < rows; i++){
         for (int j = 0; j < cols; j++){
            grid[i][j] = newGrid[i][j];
         }
      }
   }
   return 0;
}