import socket

# เชื่อมต่อกับ Oracle
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(("10.22.5.100", 21290))

# ค้นหาความยาวของ flag
for i in range(0, 15):
    plaintext = "A" * (15 - i)
    sock.send(plaintext.encode())
    ciphertext = sock.recv(1024).decode()
    if len(ciphertext) > 15 - i:
        flag_length = len(ciphertext) - (15 - i)
        break

# ค้นหา flag ทีละ byte
flag = ""
for i in range(flag_length):
    plaintext = "A" * (15 - i) + "B" * i
    sock.send(plaintext.encode())
    ciphertext = sock.recv(1024).decode()
    flag += ciphertext[i]

# พิมพ์ flag
print(flag)