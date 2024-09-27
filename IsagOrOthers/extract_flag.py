import socket

IP = '10.22.5.100'
PORT = 39833

BLOCK_SIZE = 16

def get_ciphertext(plaintext):
    # สร้าง socket
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((IP, PORT))
    
    # ส่ง plaintext ไปยังเซิร์ฟเวอร์
    s.sendall(plaintext.encode())
    
    # รับ ciphertext ที่เข้ารหัสจากเซิร์ฟเวอร์
    ciphertext = s.recv(1024)
    s.close()
    
    return ciphertext

def find_known_values():
    known_values = []
    num_blocks = 0
    while True:
        plaintext = 'A' * (BLOCK_SIZE - 1 - len(known_values))
        ciphertext = get_ciphertext(plaintext)
        
        if len(ciphertext) > num_blocks * BLOCK_SIZE:
            num_blocks += 1

            if len(ciphertext) >= num_blocks * BLOCK_SIZE - 3:
                known_values.append(ciphertext[num_blocks * BLOCK_SIZE - 3])
            else:
                break
        else:
            break
    return known_values, num_blocks

def brute_force_ecb(known_values, num_blocks):
    flag = ""
    
    possible_chars = list(range(48, 58)) + list(range(65, 91)) + list(range(97, 123)) + [43, 47, 61]
    
    for block_index in range(num_blocks):
        for char in possible_chars:

            plaintext = 'A' * (BLOCK_SIZE - 1) + chr(char) + 'A' * (BLOCK_SIZE - 1)
            ciphertext = get_ciphertext(plaintext)
            
            if ciphertext[BLOCK_SIZE * block_index + 13] == known_values[block_index]:
                flag += chr(char)
                break
                
    return flag

known_values, num_blocks = find_known_values()
print("Known Values:", known_values)
print("Number of Blocks:", num_blocks)


flag = brute_force_ecb(known_values, num_blocks)
print("Flag:", flag)
