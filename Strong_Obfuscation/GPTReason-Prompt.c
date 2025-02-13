#include <stdint.h>

// Decompiled version of _obfuscated_function from the assembly.
uint32_t obfuscated_function(uint32_t x) {
    // --- Function Prologue ---
    // In assembly, the input 'x' (in %edi) is stored at -8(%rbp).
    // A state variable is set to 0 at -12(%rbp) and 'value' is initialized with 'x' at -16(%rbp).
    uint32_t state = 0;   // Controls the jump table; corresponds to -12(%rbp)
    uint32_t value = x;   // Working copy of the input; corresponds to -16(%rbp)

    // --- Main Loop ---
    // This loop corresponds to the repeated jumps (LBB0_1, LBB0_8) in the assembly.
    while (1) {
        // --- Guard Check ---
        // Assembly: subtracts 4 from state and uses "ja LBB0_7" to branch if state > 4.
        if (state > 4) {
            // LBB0_7: sets the return value to -1 if an invalid state is encountered.
            return (uint32_t)-1;
        }

        // --- Jump Table Dispatch ---
        // The assembly uses a jump table (LJTI0_0) to dispatch to one of the cases based on 'state'.
        switch (state) {
            case 0: {
                // LBB0_2:
                // Assembly: loads value from -16(%rbp), applies xorl $1515870810 (i.e. XOR with 0x5A5A5A5A),
                // then stores the result back and sets state to 1.
                value ^= 0x5A5A5A5A;
                state = 1;
                break;
            }
            case 1: {
                // LBB0_3:
                // Assembly: rotates 'value' left by 3 bits using shift left and shift right (shll $3, shrl $29)
                // then combines them with orl, and sets state to 2.
                value = (value << 3) | (value >> (32 - 3));
                state = 2;
                break;
            }
            case 2: {
                // LBB0_4:
                // Assembly: adds a signed constant -559038737 (0xDEADBEEF) to 'value'
                // (i.e. subtracts 559038737) and then sets state to 3.
                value += -559038737;  // equivalent to: value = value - 559038737;
                state = 3;
                break;
            }
            case 3: {
                // LBB0_5:
                // Assembly: subtracts 305419896 (0x12345678) from 'value'
                // and sets state to 4.
                value -= 305419896;
                state = 4;
                break;
            }
            case 4: {
                // LBB0_6:
                // Assembly: moves 'value' into the return register and jumps to function exit.
                return value;
            }
        }
        // After each case, the loop continues (assembly: jump to LBB0_1 via LBB0_8)
    }
}
