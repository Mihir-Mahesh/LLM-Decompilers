#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Decrypts a string in place by XOR-ing each byte with 0x90.
void decrypt_string(char *str, size_t len) {
    for (size_t i = 0; i < len; i++) {
        str[i] ^= 0x90;
    }
}

// Computes a magic number from three integers.
int calc_magic_number(int a, int b, int c) {
    int result = a * b;         // Multiply first two arguments.
    result = result + c;        // Add third argument.
    result = result / 3;        // Divide the sum by 3 (integer division).
    result = result ^ (7 * b);  // XOR with (7 * second argument).
    return result;
}

// This obfuscated function decrypts a hidden message and computes a result
// from several calls to calc_magic_number. Depending on a modulus test,
// it returns either an integer derived from the decrypted message or the computed value.
int obfuscated_function(void) {
    /* 
       The encrypted message is stored as an 8-byte literal.
       In the assembly it is defined as:
           "\0223\000(;.?>"
       which represents the bytes: 0x12, '3', 0x00, '(', ';', '.', '?', '>'.
       We copy these 8 bytes into a local buffer and then decrypt in place.
    */
    char encrypted[8];
    const char encrypted_literal[8] = "\0223\0(;.?>";
    memcpy(encrypted, encrypted_literal, 8);

    // Decrypt the 8-byte string.
    decrypt_string(encrypted, 8);

    // Compute three magic numbers using fixed constants.
    int r1 = calc_magic_number(15, 27, 38);
    int r2 = calc_magic_number(34, 56, 21);
    int r3 = calc_magic_number(73, 14, 9);

    // Combine the three results:
    //   Let A = r1, B = r2, C = r3.
    //   Compute d = (A + B + C) XOR (A + B)
    int d = (r1 + r2 + r3) ^ (r1 + r2);

    // Check if d is divisible by 19.
    int result;
    if ((d % 19) == 0) {
        // If so, return the first 4 bytes of the decrypted message interpreted as an int.
        result = *(int *)encrypted;
    } else {
        // Otherwise, return the computed magic number combination.
        result = d;
    }
    return result;
}

