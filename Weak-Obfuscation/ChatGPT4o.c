#include <stdio.h>

void decrypt_string(char *str, size_t len) {
    for (size_t i = 0; i < len; i++) {
        str[i] ^= 90;  // XOR decryption with key 90
    }
}

int calc_magic_number(int a, int b, int c) {
    int result = (a * b + c) / 3;
    result ^= (b * 7);
    return result;
}

int obfuscated_function() {
    char encrypted_msg[] = {0x12, 0x33, 0x00, 0x28, 0x3B, 0x2E, 0x3F, 0x3E}; // Encrypted data
    size_t msg_len = sizeof(encrypted_msg);
    
    decrypt_string(encrypted_msg, msg_len);

    int val1 = calc_magic_number(15, 27, 38);
    int val2 = calc_magic_number(34, 56, 21);
    int val3 = calc_magic_number(73, 14, 9);
    
    int combined = (val1 + val2 + val3) ^ (val1 + val2);
    
    return (combined % 19 == 0) ? encrypted_msg[0] : combined;
}
