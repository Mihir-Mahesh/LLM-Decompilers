#include <stdio.h>

void decrypt_string(char* str, size_t len) {
    for(size_t i = 0; i < len; i++) {
        str[i] ^= 90;  // XOR with 0x5A
    }
}

int calc_magic_number(int a, int b, int c) {
    int result = a * b;
    result = (result + c) / 3;
    result ^= (b * 7);
    return result;
}

int obfuscated_function() {
    char encrypted_msg[8] = "\0223\000(;.?>";  // Encrypted constant
    size_t msg_len = 8;
    
    // Decrypt the message
    decrypt_string(encrypted_msg, msg_len);
    
    // Calculate three magic numbers
    int magic1 = calc_magic_number(15, 27, 38);
    int magic2 = calc_magic_number(34, 56, 21);
    int magic3 = calc_magic_number(73, 14, 9);
    
    // Combine the magic numbers
    int combined = magic1 + magic2 + magic3;
    combined ^= (magic1 + magic2);
    
    // Final result depends on divisibility by 19
    int result;
    if (combined % 19 == 0) {
        result = *(int*)encrypted_msg;  // First 4 bytes of decrypted message
    } else {
        result = combined;
    }
    
    return result;
}
