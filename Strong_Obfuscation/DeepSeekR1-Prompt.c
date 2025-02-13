int obfuscated_function(int input) {
    /* 
      Stack variable mapping:
      - input   -> edi/-8(%rbp)   (32-bit)
      - state   -> -12(%rbp)      (32-bit)
      - value   -> -16(%rbp)      (32-bit)
    */
    uint32_t state = 0;        // -12(%rbp) in assembly
    uint32_t value = input;    // -16(%rbp) in assembly

    // Loop header (LBB0_1 in assembly)
    for (;;) {
        // State bounds check (subq $4 + ja LBB0_7)
        if (state > 4) {
            return -1;  // LBB0_7 logic
        }

        // Jump table implementation (LJTI0_0)
        switch (state) {
            // Case 0: XOR (LBB0_2)
            case 0:
                value ^= 0x5A5A5A5A;  // xorl $0x5A5A5A5A
                state = 1;            // movl $1, -12(%rbp)
                break;

            // Case 1: Rotate left by 3 (LBB0_3)
            case 1:
                value = (value << 3) | (value >> 29);  // shll $3 + shrl $29
                state = 2;
                break;

            // Case 2: Add 0xDEADBEEF (LBB0_4)
            case 2:
                value += 0xDEADBEEF;  // addl $-559038737 (same hex)
                state = 3;
                break;

            // Case 3: Subtract 0x12345678 (LBB0_5)
            case 3:
                value -= 0x12345678;  // subl $305419896
                state = 4;
                break;

            // Case 4: Return result (LBB0_6)
            case 4:
                return (int)value;  // movl -16(%rbp), %eax

            // Default: Should never be reached (handled by state>4 check)
            default:
                return -1;
        }
    }
}
