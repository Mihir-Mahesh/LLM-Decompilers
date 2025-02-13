#include <stdio.h>

int sum_of_squares(int n) {
    if (n <= 0) return 0;

    // Closed-form polynomial term (matches LBB0_2 calculations)
    int polynomial_term = 
        ((n-1)*(n-2)*(n-3))/6 +  // Cubic component (RAX path)
        5*((n-1)*(n-2))/2 +       // Quadratic component (RCX path)
        4*n - 3;                  // Linear offset

    int total = polynomial_term;

    // Even-numbered special handling (LBB0_4/LBB0_6)
    if (n % 2 == 0) {
        // Sum ⌊dx²/3⌋ for dx=1 to dx=n-1 (matches loop in LBB0_6)
        for (int dx = 1; dx < n; dx++) {
            // Magic constant 0xAAAAAAAB ≈ (2^33)/3 for division
            total += (int)((dx * (long long)dx * 0xAAAAAAAB) >> 33);
        }
    }

    // Recursive subdivision (LBB0_8)
    if (n >= 2) {
        // Compute n/2 with proper rounding (matches SHR/ADD/SAR sequence)
        int half = (n + (n >> 31)) >> 1;  // Assembly's signed division
        total += sum_of_squares(half);
    }

    // Final combination (LBB0_9)
    return total + n*n*n + n;
}
