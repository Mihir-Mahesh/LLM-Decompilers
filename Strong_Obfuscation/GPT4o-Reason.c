int obfuscated_function(int input) {
    int value = input;
    int state = 0;

    while (1) {
        switch (state) {
            case 0:
                value ^= 0x5A5A5A5A;
                state = 1;
                break;
            case 1:
                // Rotate left by 3 bits (for a 32-bit integer)
                value = (value << 3) | ((unsigned)value >> 29);
                state = 2;
                break;
            case 2:
                value -= 0xDEADBEEF;  // 0xDEADBEEF interpreted as signed is -559038737
                state = 3;
                break;
            case 3:
                value -= 0x12345678;
                state = 4;
                break;
            case 4:
                return value;
            default:
                return -1;
        }
    }
}
