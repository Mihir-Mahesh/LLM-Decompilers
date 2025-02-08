#define XOR_KEY 0x5A
#define ENCRYPTED_STR {0x48 ^ XOR_KEY, 0x69 ^ XOR_KEY, 0x5A ^ XOR_KEY, 0x72 ^ XOR_KEY, 0x61 ^ XOR_KEY, 0x74 ^ XOR_KEY, 0x65 ^ XOR_KEY, 0x64 ^ XOR_KEY}


void decrypt_string(unsigned char* encrypted, size_t len) {
   for (size_t i = 0; i < len; i++) {
       encrypted[i] ^= XOR_KEY;
   }
}


int calc_magic_number(int a, int b, int c) {
   int result = a * b;
   result = (result + c) / 3;
   result = result ^ (b * 7);
   return result;
}


int obfuscated_function() {
   unsigned char encrypted_msg[] = ENCRYPTED_STR;
   size_t len = sizeof(encrypted_msg) / sizeof(encrypted_msg[0]);


   // Decrypt the message at runtime
   decrypt_string(encrypted_msg, len);


   // Obfuscate calculations
   int x = calc_magic_number(15, 27, 38);
   int y = calc_magic_number(34, 56, 21);
   int z = calc_magic_number(73, 14, 9);
   int final_result = (x + y + z) ^ (x + y);


   // Complex check for added obfuscation
   if ((final_result % 19) == 0) {
       return *(int*)encrypted_msg;  // Return an obfuscated result
   } else {
       return final_result;  // Return final result as fallback
   }
}
