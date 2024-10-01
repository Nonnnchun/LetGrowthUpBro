//SECTION : Read CSV File -----------------------------------------------------------------------------------------

/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
   int no;
   double lat;
   double lon;
}info;

void printInfo(info rec){
   printf("no : %d\t latitude : %f\t longitude :%f\n", rec.no, rec.lat, rec.lon);
}

void readCSV(){
   FILE *fpr = fopen("latlonfile.csv", "r");
   char line[100];
   info rec;
   char *token;
   char *delim = ",";

   if (fpr == NULL){
      printf("Error opening file\n");
      return;
   }

   while (fgets(line, sizeof(line), fpr) != NULL){
      line[strcspn(line, "\n")] = 0;
      token = strtok(line, delim);
      int col = 1;
      while (token != NULL){
         switch (col){
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
} */

// NOTE : Use Curl To Solve --------------------------------------------------------------------------------------

/* #define CURL_STATICLIB
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

typedef struct
{
   int no;
   double lat;
   double lon;
   char place[8192]; // ใช้เก็บชื่อสถานที่
} info;

struct MemoryStruct
{
   char *memory;
   size_t size;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *mem)
{
   size_t realsize = size * nmemb;
   mem->memory = realloc(mem->memory, mem->size + realsize + 1);
   if (mem->memory == NULL)
   {
      printf("Not enough memory!\n");
      return 0; // out of memory
   }
   memcpy(&(mem->memory[mem->size]), contents, realsize);
   mem->size += realsize;
   mem->memory[mem->size] = 0; // Null terminate
   return realsize;
}

void queryPlace(info *rec)
{
   CURL *curl;
   CURLcode res;
   char url[256];

   // สร้าง URL สำหรับ query
   snprintf(url, sizeof(url), "https://nominatim.openstreetmap.org/reverse?format=json&lat=%.6f&lon=%.6f", rec->lat, rec->lon);
   printf("Calling API: %s\n", url); // แสดง URL ที่เรียก

   struct MemoryStruct chunk;
   chunk.memory = malloc(4096); // กำหนดขนาด buffer เริ่มต้นเป็น 4,096 ไบต์
   chunk.size = 0;              // ไม่มีข้อมูลในตอนเริ่มต้น

   curl_global_init(CURL_GLOBAL_ALL);
   curl = curl_easy_init();
   if (curl)
   {
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
      curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0"); // เพิ่ม User-Agent
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);

      if (res == CURLE_OK)
      {
         // แสดงข้อมูลที่ได้รับจาก API
         printf("API Response: %s\n", chunk.memory);

         // แยกชื่อสถานที่ออกจาก JSON response
         char *place_start = strstr(chunk.memory, "\"display_name\":\"");
         if (place_start)
         {
            place_start += strlen("\"display_name\":\"");
            char *place_end = strchr(place_start, '\"');
            if (place_end)
            {
               *place_end = '\0';
               strncpy(rec->place, place_start, sizeof(rec->place) - 1);
               rec->place[sizeof(rec->place) - 1] = '\0'; // ป้องกัน buffer overflow
            }
            else
            {
               strcpy(rec->place, "Unknown Place"); // กรณีไม่พบชื่อสถานที่
            }
         }
         else
         {
            strcpy(rec->place, "Unknown Place"); // กรณีไม่พบชื่อสถานที่
         }
      }
      else
      {
         printf("Error in API request: %s\n", curl_easy_strerror(res));
         strcpy(rec->place, "API Error"); // กรณี API มีปัญหา
      }
      free(chunk.memory); // คืน memory ที่ใช้แล้ว
   }
   curl_global_cleanup();
}

void readCSV(const char *student_id)
{
   FILE *fpr = fopen("latlonfile.csv", "r");
   FILE *fpw = fopen(student_id, "w");
   char line[100];
   info rec;
   char *token;
   char *delim = ",";
   int first_row = 1;

   if (fpr == NULL || fpw == NULL)
   {
      printf("Error opening file\n");
      return;
   }

   fprintf(fpw, "no,lat,lon,place\n");

   while (fgets(line, sizeof(line), fpr) != NULL)
   {
      line[strcspn(line, "\n")] = 0;
      token = strtok(line, delim);
      int col = 1;
      while (token != NULL)
      {
         switch (col)
         {
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
      printf("Reading from CSV: no=%d, lat=%.6f, lon=%.6f\n", rec.no, rec.lat, rec.lon);

      // ข้ามข้อมูลที่ latitude และ longitude เป็น 0
      if (rec.lat == 0.0 && rec.lon == 0.0)
      {
         printf("Skipping entry with no=%d due to invalid coordinates\n", rec.no);
         continue; // ข้ามไปยังลูปถัดไป
      }

      queryPlace(&rec);

      // ตรวจสอบว่ากำลังเขียนบรรทัดแรกหรือไม่
      if (!first_row)
      {
         fprintf(fpw, "\n"); // ขึ้นบรรทัดใหม่เฉพาะเมื่อไม่ใช่บรรทัดแรก
      }
      fprintf(fpw, "%d,%.6f,%.6f,%s", rec.no, rec.lat, rec.lon, rec.place);
      first_row = 0; // ตั้งค่าให้เป็นบรรทัดถัดไปหลังจากเขียนบรรทัดแรกแล้ว
   }

   fclose(fpr);
   fclose(fpw);
}

int main()
{
   char student_id[] = "67011509.csv"; // เปลี่ยนรหัสนักศึกษาเป็นค่าที่ต้องการ
   readCSV(student_id);
   return 0;
} */

// SECTION : Test API Without Curl Library <Curl in terminal> -----------------------------------------------------

/* #include <stdio.h>
#include <stdlib.h>
int main(){
   char url[512];
   // Get the URL from the user
   printf("Enter the URL of the API: ");
   scanf("%255s", url);
   // Create a command string
   char command[512];
   snprintf(command, sizeof(command), "curl -s \"%s\"", url);
   printf("%s",command);
   // Execute the curl command

   int result = system(command);
   // Check if the curl command was successful
   if (result != 0){
      printf("curl command failed\n");
   }
   return 0;
} */


//NOTE : Solve Without Curl <Curl in terminal> --------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void curl_search(double lat, double lon, char *json_output, size_t json_output_size)
{
   char url[256]; // The buffer to store the final URL
   snprintf(url, sizeof(url), "https://nominatim.openstreetmap.org/reverse?format=json&lat=%.6f&lon=%.6f", lat, lon);
   // Create a command string
   char command[512];
   snprintf(command, sizeof(command), "curl \"%s\"", url);
   // Execute the curl command
   int result = system(command);

   // Use popen to run the command and read the output
   FILE *fp = popen(command, "r");
   if (fp == NULL)
   {
      printf("Failed to run curl command\n");
      return;
   }

   // Buffer to hold the output
   char output[2048];

   json_output[0] = '\0';

   // Read the output from the command
   while (fgets(output, sizeof(output), fp) != NULL)
   {
      // Check if there's enough space in json_output to append the new data
      if (strlen(json_output) + strlen(output) < json_output_size - 1)
      {
         // Concatenate the new output to json_output
         strncat(json_output, output, json_output_size - strlen(json_output) - 1);
      }
      else
      {
         // If there's not enough space, print an error and break
         printf("Output exceeds buffer size\n");
         break;
      }
   }

   // Close the file pointer
   pclose(fp);
}

void extract_description(const char *json_data, char *description)
{
   const char *key = "\"display_name\":";
   // Find the "description" key in the JSON data
   const char *pos = strstr(json_data, key);

   if (pos)
   {
      // Move the pointer to the beginning of the description value
      pos += strlen(key);
      // Skip any spaces or quotes
      while (*pos == ' ' || *pos == '"')
         pos++;
      // Copy the description content until the closing quote
      int i = 0;
      while (*pos != '"' && *pos != '\0')
      {
         description[i++] = *pos++;
      }
      description[i] = '\0'; // Null-terminate the string
   }
   else
   {
      strcpy(description, "Description not found");
   }
}

int main()
{
   typedef struct
   {
      int id;
      double lat;
      double lon;
      char place[1024];
   } LOCATION;

   LOCATION locations[3];

   FILE *fp;
   fp = fopen("latlonfile.csv", "r");

   if (fp == NULL)
   {
      printf("Unable to open file");
      return 1;
   }

   int i = 0;
   char line[50];
   fgets(line, sizeof(line), fp); // pass header

   while (fgets(line, sizeof(line), fp))
   {
      char *field = strtok(line, ",");
      if (field != NULL)
         locations[i].id = atoi(field);

      field = strtok(NULL, ",");
      if (field != NULL)
         locations[i].lat = atof(field);

      field = strtok(NULL, ",");
      if (field != NULL)
         locations[i].lon = atof(field);

      i++;
   }

   fclose(fp);

   // curl search, extract name, assign valve
   for (int i = 0; i < 3; i++)
   {
      char json_data[2048];
      curl_search(locations[i].lat, locations[i].lon, json_data, sizeof(json_data));
      char name[1024];
      extract_description(json_data, name);
      strcpy(locations[i].place, name);
   }

   // write file
   FILE *file = fopen("67010247.csv", "w");

   if (file == NULL)
   {
      printf("Error opening file!\n");
      return 1;
   }

   fprintf(file, "no,lat,lon,place\n");
   for (int i = 0; i < 3; i++)
   {
      // ตรวจสอบว่าบรรทัดนี้เป็นบรรทัดสุดท้ายหรือไม่
      if (i < 2) // เขียน newline ถ้าไม่ใช่บรรทัดสุดท้าย
      {
         fprintf(file, "%d,%lf,%lf,%s\n", locations[i].id, locations[i].lat, locations[i].lon, locations[i].place);
      }
      else // ไม่ใส่ newline ในบรรทัดสุดท้าย
      {
         fprintf(file, "%d,%lf,%lf,%s", locations[i].id, locations[i].lat, locations[i].lon, locations[i].place);
      }
   }

   fclose(file);

   return 0;
}