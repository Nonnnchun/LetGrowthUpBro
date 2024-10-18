#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 19 // Number of rows in the maze
#define COLS 21 // Number of columns in the maze

// Directions: Up, Down, Left, Right
int directions[4][2] = {{-1, 0},
                        {1, 0},
                        {0, -1},
                        {0, 1}};

bool solveMaze(char maze[ROWS][COLS], int x, int y);
void saveMazeToFile(char maze[ROWS][COLS], char *filename);

int main(){
   char maze[ROWS][COLS];
   FILE *file = fopen("MAP01.TXT", "r");

   if (file == NULL){
      printf("Error opening file.\n");
      return 1;
   }

   // Read the maze from the file
   for (int i = 0; i < ROWS; i++){
      fgets(maze[i], COLS + 2, file); // +2 to account for newline and null terminator \n \0

      // Ensure that each row of the maze has a length of 20 characters
      maze[i][COLS - 1] = '\0'; // Trim newline

      if (strlen(maze[i]) < COLS){
         for (int j = strlen(maze[i]); j < COLS - 1; j++){
            maze[i][j] = '#'; // Fill with '#' to complete 20 characters
         }
      }
      if (i != ROWS - 1){
         maze[i][COLS - 1] = '\n'; // Add newline back
      } else{
         maze[i][COLS - 1] = '\t'; // '\t' means '\0' //NOTE: If maze[i][COLS - 1] = '\0' it's show NULL in file
      }
   }
   fclose(file);

   // Find the starting position 'S'
   int startX, startY;
   for (int i = 0; i < ROWS; i++){
      for (int j = 0; j < COLS; j++){
         if (maze[i][j] == 'S' || maze[i][j] == 's'){
            maze[i][j] = 's';
            startX = i;
            startY = j;
            break;
         }
      }
   }

   // Solve the maze
   if (solveMaze(maze, startX, startY)){
      saveMazeToFile(maze, "67011509.txt"); // Change YOUR_STUDENT_ID to the actual student ID
   } else{
      printf("No path found.\n");
   }

   return 0;
}

// Recursive function to find the exit in the maze
bool solveMaze(char maze[ROWS][COLS], int x, int y){
   if (maze[x][y] == 'E' || maze[x][y] == 'e'){
      return true; // Exit found
   }

   // Mark the current position
   if (maze[x][y] != 's'){ // Do not change S to +
      maze[x][y] = '+'; // Mark as part of the path
   }

   // Try moving in all directions
   for (int i = 0; i < 4; i++){
      int newX = x + directions[i][0];
      int newY = y + directions[i][1];

      // Check if the new position is valid (within bounds and not a wall or already visited)
      if ((newX >= 0) && (newX < ROWS) && (newY >= 0) && (newY < COLS) && ((maze[newX][newY] == ' ') || (maze[newX][newY] == 'E'))){
         if (solveMaze(maze, newX, newY)){
            return true; // Path found
         }
      }
   }

   // If no path is found, backtrack
   if (maze[x][y] != 's'){ // Do not erase the S marker
      maze[x][y] = ' '; // Un-mark the path
   }
   return false; // No path found
}

// Save the maze to a file
void saveMazeToFile(char maze[ROWS][COLS], char *filename){
   FILE *file = fopen(filename, "w");
   for (int i = 0; i < ROWS; i++){
      for (int j = 0; j < COLS; j++){
         fputc(maze[i][j], file); // Write each character to the file
      }
   }
   fclose(file); // Close the file
}