
#include <stdio.h>
#include <stdint.h>

#define OBF1(x) ((x) ^ 0x5A5A5A5A)
#define OBF2(x) (((x) << 3) | ((x) >> (32 - 3)))
#define OBF3(x) ((x) + 0xDEADBEEF)
#define OBF4(x) ((x) - 0x12345678)

int obfuscated_function(int input) {
    int state = 0;
    /* Work with an unsigned 32-bit value for bit-level operations */
    uint32_t var = (uint32_t) input;

    while (1) {
        switch(state) {
            case 0:
                /* First obfuscation step */
                var = OBF1(var);
                state = 1;
                break;
            case 1:
                /* Second step: a combined shift/mix */
                var = OBF2(var);
                state = 2;
                break;
            case 2:
                /* Third step: add a magic constant */
                var = OBF3(var);
                state = 3;
                break;
            case 3:
                /* Fourth step: subtract a magic constant */
                var = OBF4(var);
                state = 4;
                break;
            case 4:
                /* End state: return the final result */
                return (int) var;
            default:
                /* Should never happen */
                return -1;
        }
    }
}
