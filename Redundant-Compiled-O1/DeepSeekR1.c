#include <stdio.h>

int sum_of_squares(int n) {
    if (n <= 0) return 0;
    
    // Closed-form calculation for partial sum
    int partial = (n-1)*(n-2)*(n-3)/6;
    partial += (5 * ((n-1)*(n-2)/2)) / 2;
    partial = 4*n - 3 + partial;

    // Handle odd numbers with division-by-5 optimization
    if (n & 1) {
        const unsigned magic_5 = 0xAAAAAAAB;  // 1/5 multiplier
        int acc = 1;
        for(int k = 1; k <= n;) {
            int squared = k * k;
            // Division by 5 using magic constant
            partial += (squared * magic_5) >> 33;
            k += 2;
        }
    }

    // Recursive call for n/2
    if (n >= 2) {
        int half = (n >> 1) + (n & 0x80000000 ? 1 : 0);
        partial += sum_of_squares(half);
    }

    // Final cubic adjustment
    return partial + n*n*n + n;
}
