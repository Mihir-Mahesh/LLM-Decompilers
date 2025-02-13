#include <stdio.h>

int obfuscated_function(int input) {
    int state = 0;
    int value = input;
    
    while (1) {
        switch (state) {
            case 0:
                // XOR with magic constant 0x5A5A5A5A
                value ^= 0x5A5A5A5A;
                state = 1;
                break;
            
            case 1:
                // Rotate left by 3 bits
                value = (value << 3) | (value >> 29);
                state = 2;
                break;
            
            case 2:
                // Subtract magic constant 0xDEADBEEF
                value -= 0xDEADBEEF;
                state = 3;
                break;
            
            case 3:
                // Subtract magic constant 0x12345678
                value -= 0x12345678;
                state = 4;
                break;
            
            case 4:
                // Final state - return result
                return value;
            
            default:
                // Error case for invalid state
                return -1;
        }
    }
}
