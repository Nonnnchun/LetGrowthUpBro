#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "10.22.5.100" // เปลี่ยนเป็น IP ของเซิร์ฟเวอร์ Oracle ของคุณ
#define SERVER_PORT 21290 // เปลี่ยนเป็นพอร์ตของเซิร์ฟเวอร์ Oracle ของคุณ
#define MAX_BUFFER_SIZE 1024

int main() {
  // สร้าง socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    exit(1);
  }

  // เชื่อมต่อกับเซิร์ฟเวอร์
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // ค้นหาความยาวของ flag
  int flag_length = 0;
  for (int i = 1; i <= 15; i++) {
    char plaintext[MAX_BUFFER_SIZE];
    memset(plaintext, 'A', sizeof(plaintext));
    plaintext[i] = 'B';

    send(sock, plaintext, sizeof(plaintext), 0);
    char ciphertext[MAX_BUFFER_SIZE];
    int recv_len = recv(sock, ciphertext, sizeof(ciphertext), 0);

    if (recv_len > i) {
      flag_length = recv_len - i;
      break;
    }
  }

  // ค้นหา flag ทีละ byte
  char flag[flag_length + 1];
  memset(flag, '\0', sizeof(flag));

  for (int i = 0; i < flag_length; i++) {
    char plaintext[MAX_BUFFER_SIZE];
    memset(plaintext, 'A', sizeof(plaintext));
    plaintext[flag_length - i - 1] = 'B';

    send(sock, plaintext, sizeof(plaintext), 0);
    char ciphertext[MAX_BUFFER_SIZE];
    int recv_len = recv(sock, ciphertext, sizeof(ciphertext), 0);

    flag[i] = ciphertext[flag_length - i - 1];
  }

  // พิมพ์ flag
  printf("Flag: %s\n", flag);

  // ปิด socket
  close(sock);

  return 0;
}