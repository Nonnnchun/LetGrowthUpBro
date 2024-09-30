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

// NOTE : ---------------------------------------------------------------------------------------------------------------

/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

typedef struct{
   int no;
   double lat;
   double lon;
   char place[256]; // ใช้เก็บชื่อสถานที่
} info;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
   strncat(userp, contents, size * nmemb);
   return size * nmemb;
}

void queryPlace(info *rec){
   CURL *curl;
   CURLcode res;
   char url[256];
   char response[512] = ""; // Buffer สำหรับเก็บข้อมูลตอบกลับ

   // สร้าง URL สำหรับ query
   snprintf(url, sizeof(url), "https://nominatim.openstreetmap.org/reverse?format=json&lat=%.6f&lon=%.6f", rec->lat, rec->lon);

   curl_global_init(CURL_GLOBAL_ALL);
   curl = curl_easy_init();
   if (curl){
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);

      // แยกชื่อสถานที่ออกจาก JSON response
      char *place_start = strstr(response, "\"display_name\":\"");
      if (place_start){
         place_start += strlen("\"display_name\":\"");
         char *place_end = strchr(place_start, '\"');
         if (place_end){
            *place_end = '\0';
            strncpy(rec->place, place_start, sizeof(rec->place) - 1);
            rec->place[sizeof(rec->place) - 1] = '\0'; // ป้องกัน buffer overflow
         }
      }
   }
   curl_global_cleanup();
}

void readCSV(const char *student_id){
   FILE *fpr = fopen("latlonfile.csv", "r");
   FILE *fpw = fopen(student_id, "w"); // สร้างไฟล์ใหม่ตามรหัสนักศึกษา
   char line[100];
   info rec;
   char *token;
   char *delim = ",";

   if (fpr == NULL || fpw == NULL){
      printf("Error opening file\n");
      return;
   }

   fprintf(fpw, "no,lat,lon,place\n"); // เขียน header ลงไฟล์ใหม่

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
      queryPlace(&rec);
      fprintf(fpw, "%d,%.6f,%.6f,%s\n", rec.no, rec.lat, rec.lon, rec.place);
   }
   fclose(fpr);
   fclose(fpw);
}

int main(){
   char student_id[] = "67011509.csv"; // เปลี่ยนรหัสนักศึกษาเป็นค่าที่ต้องการ
   readCSV(student_id);
   return 0;
} */


// SECTION : Test

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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
   int no;
   double lat;
   double lon;
   char place[256]; // ใช้เก็บชื่อสถานที่
} info;

void queryPlace(info *rec)
{
   char url[256];
   char response[512];
   FILE *fp;

   snprintf(url, sizeof(url), "https://nominatim.openstreetmap.org/reverse?format=json&lat=%.6f&lon=%.6f", rec->lat, rec->lon);

   char command[512];
   snprintf(command, sizeof(command), "curl -s \"%s\"", url);

   fp = popen(command, "r");
   if (fp == NULL)
   {
      printf("Failed to run command\n");
      return;
   }

   fread(response, sizeof(char), sizeof(response) - 1, fp);
   response[sizeof(response) - 1] = '\0'; // เพิ่ม null terminator
   pclose(fp);

   // แสดงผล JSON response ใน Terminal
   printf("Response for (%d, %.6f, %.6f): %s\n", rec->no, rec->lat, rec->lon, response);

   // แยกชื่อสถานที่ออกจาก JSON response
   char *place_start = strstr(response, "\"display_name\":\"");
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
         strncpy(rec->place, "Unknown", sizeof(rec->place) - 1);
      }
   }
   else
   {
      strncpy(rec->place, "Unknown", sizeof(rec->place) - 1);
   }

   // แสดงชื่อสถานที่ใน Terminal
   printf("Place for (%d): %s\n", rec->no, rec->place);
}

void readCSV(const char *student_id)
{
   FILE *fpr = fopen("latlonfile.csv", "r");
   FILE *fpw = fopen(student_id, "w"); // สร้างไฟล์ใหม่ตามรหัสนักศึกษา
   char line[100];
   info rec;
   char *token;
   char *delim = ",";

   if (fpr == NULL || fpw == NULL)
   {
      printf("Error opening file\n");
      return;
   }

   fprintf(fpw, "no,lat,lon,place\n"); // เขียน header ลงไฟล์ใหม่

   while (fgets(line, sizeof(line), fpr) != NULL)
   {
      line[strcspn(line, "\n")] = 0; // ลบ newline character
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

      // เรียกฟังก์ชัน queryPlace เพื่อดึงชื่อสถานที่
      queryPlace(&rec);

      // เขียนบรรทัดลงไฟล์เฉพาะเมื่อมีชื่อสถานที่ที่ถูกต้อง
      if (strcmp(rec.place, "Unknown") != 0)
      {
         fprintf(fpw, "%d,%.6f,%.6f,%s\n", rec.no, rec.lat, rec.lon, rec.place);
      }
   }

   fclose(fpr);
   fclose(fpw);
}

int main()
{
   char student_id[] = "67011509.csv"; // เปลี่ยนรหัสนักศึกษาเป็นค่าที่ต้องการ
   readCSV(student_id);
   return 0;
}
