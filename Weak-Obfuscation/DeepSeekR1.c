#include <stdio.h>
#include <stdint.h>

// Decrypts a string using XOR cipher with key 0x5A (90)
void decrypt_string(char *str, size_t length) {
    for (size_t i = 0; i < length; i++) {
        str[i] ^= 0x5A; // XOR with 'Z'
    }
}

// Obfuscated mathematical calculation
int calc_magic_number(int a, int b, int c) {
    int result = a * b;
    result += c;
    result /= 3;          // Integer division
    result ^= (b * 7);    // XOR with 7 times second parameter
    return result;
}

// Main obfuscated logic with stack protection
int obfuscated_function(void) {
    // Encrypted message (will be decrypted in-place)
    char encrypted_msg[8] = {0x12, 0x33, 0x00, 0x28, 0x3B, 0x2E, 0x3F, 0x3E};
    const size_t msg_len = 8;

    // Decrypt the message
    decrypt_string(encrypted_msg, msg_len);

    // Calculate magic numbers
    int magic1 = calc_magic_number(15, 27, 38);
    int magic2 = calc_magic_number(34, 56, 21);
    int magic3 = calc_magic_number(73, 14, 9);

    // Combine results
    int combined = magic1 + magic2 + magic3;
    combined ^= (magic1 + magic2);  // XOR combination

    // Decision logic based on divisibility
    int final_result;
    if (combined % 19 == 0) {
        // Use first 4 bytes of decrypted message as integer
        final_result = *(int*)encrypted_msg;
    } else {
        final_result = combined;
    }

    return final_result;
}
