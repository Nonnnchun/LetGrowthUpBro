import socket

# เชื่อมต่อกับ Oracle
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(("10.22.5.100", 43570))

# ค้นหาความยาวของ flag
for i in range(16, 33):
    plaintext = "A" * i
    sock.send(plaintext.encode())
    ciphertext = sock.recv(1024).decode()
    if len(ciphertext) > i:
        flag_length = len(ciphertext) - i
        break

# ค้นหา flag ทีละ byte
flag = ""
for i in range(flag_length):
    plaintext = "A" * (15 - i) + "B" * i
    sock.send(plaintext.encode())
    ciphertext = sock.recv(1024).decode()
    flag += ciphertext[15 + i]

# พิมพ์ flag
print(flag)