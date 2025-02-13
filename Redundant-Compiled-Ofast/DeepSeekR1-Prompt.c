#include <stdio.h>

int sum_of_squares(int n) {
    if (n <= 0) return 0;

    // Part 1: Precompute combinatorial terms
    int term1 = (n-1) * (n-2) * (n-3) / 6;   // C(n-1,3)
    int term2 = 5 * ((n-1) * (n-2) / 2);      // 5*C(n-1,2)
    int ebx = 4 * n - 3 + term1 + term2;

    // Part 2: Loop processing pairs (i, i+1)
    int i = 1;
    int magic_div3 = 0xAAAAAAAB; // Magic number for division by 3

    if (n % 2 == 0) {
        // Even n: Loop until i = n-1 (e.g., n=4 → i=1,3)
        while (2 - n + i != 1) {
            // Add (i² + (i+1)²) / 3
            int term_i = (i * i) * magic_div3;
            term_i = (int)(term_i >> 33);      // term_i = i² / 3
            int term_i_plus_1 = ((i+1) * (i+1)) * magic_div3;
            term_i_plus_1 = (int)(term_i_plus_1 >> 33); // term_i_plus_1 = (i+1)² / 3
            ebx += term_i + term_i_plus_1;
            i += 2;
        }
    } else {
        // Odd n: Loop until i = n-2 (e.g., n=5 → i=1,3)
        while (3 - n + i != 1) {
            // Add (i² + (i+1)²) / 3
            int term_i = (i * i) * magic_div3;
            term_i = (int)(term_i >> 33);
            int term_i_plus_1 = ((i+1) * (i+1)) * magic_div3;
            term_i_plus_1 = (int)(term_i_plus_1 >> 33);
            ebx += term_i + term_i_plus_1;
            i += 2;
        }
        // Add final term for odd n: n² / 3
        int term_final = (n * n) * magic_div3;
        term_final = (int)(term_final >> 33);
        ebx += term_final;
    }

    // Part 3: Recursive step for n/2
    if (n >= 2) {
        ebx += sum_of_squares(n / 2);
    }

    // Part 4: Final formula
    return n * n * n + n + ebx;
}
