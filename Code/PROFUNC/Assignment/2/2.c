#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 10000
#define MAX_PATTERN_LENGTH 100

// Function to preprocess the pattern and create the bad character table
void preprocessBadCharacter(char *pattern, int m, int badChar[])
{
   for (int i = 0; i < 256; i++)
   {
      badChar[i] = -1; // Initialize all occurrences as -1
   }
   for (int i = 0; i < m; i++)
   {
      badChar[(unsigned char)pattern[i]] = i; // Set the last occurrence of the character
   }
}

// Function to implement the Boyer-Moore search algorithm and highlight matches
void BoyerMoore(char *text, char *pattern)
{
   int n = strlen(text);
   int m = strlen(pattern);
   int badChar[256];

   // Preprocess the pattern
   preprocessBadCharacter(pattern, m, badChar);

   int s = 0; // Shift of the pattern with respect to text
   int found = 0;

   // Search for pattern
   while (s <= n - m)
   {
      int j = m - 1;

      // Keep reducing j while characters of pattern and text are matching at this shift s
      while (j >= 0 && pattern[j] == text[s + j])
      {
         j--;
      }

      // If the pattern is found
      if (j < 0)
      {
         found = 1;
         // Highlight the match and show position
         printf("*%.*s* - at position: %d\n", m, text + s, s);
         s += m; // Move past the match
      }
      else
      {
         s += (j - badChar[(unsigned char)text[s + j]] > 1) ? j - badChar[(unsigned char)text[s + j]] : 1;
      }
   }

   if (!found)
   {
      printf("No matches found.\n");
   }
}

int main()
{
   FILE *file;
   char text[MAX_TEXT_LENGTH];
   char pattern[MAX_PATTERN_LENGTH];

   // Read the text from the file
   file = fopen("boyer-moore.txt", "r");
   if (file == NULL)
   {
      printf("Could not open file.\n");
      return 1;
   }

   fread(text, sizeof(char), MAX_TEXT_LENGTH, file);
   fclose(file);

   // Ensure null-termination
   text[MAX_TEXT_LENGTH - 1] = '\0';

   // Get the keyword from user
   printf("Enter keyword to search: ");
   scanf("%s", pattern);

   // Perform the Boyer-Moore search and highlight matches
   BoyerMoore(text, pattern);

   return 0;
}