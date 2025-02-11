#include <stdio.h>

// _sum_of_squares is an obfuscated function that
// returns:   n³ + n + extra
// where extra is computed as follows:
//   - For n > 0, first compute a “magic” value:
//         magic = 4*n + (((n-3) * (n-2) * (n-1)) / 3) - 3
//   - If n is even, add the sum of i² for i = 1 to n-1.
//   - If n >= 2, add recursively sum_of_squares(n/2).
// For n <= 0 extra is 0.
int sum_of_squares(int n) {
    int extra = 0;  // corresponds to register EBX in the assembly

    if (n > 0) {
        // --- LBB0_2: Compute a “magic value” ---
        // (The assembly multiplies (n-1), (n-2), (n-3) with some shifts
        // and then adds 4*n and subtracts 3. Here we approximate that by:)
        int magic = 4 * n + (((n - 3) * (n - 2) * (n - 1)) / 3) - 3;
        extra = magic;
    } else {
        extra = 0;
    }

    // --- Even branch: LBB0_4 ... LBB0_6 ---
    // If n is even (and n > 0) then add an extra sum computed in a loop.
    // In the assembly the loop iterates for i = 1 to n-1.
    if (n > 0 && (n % 2) == 0) {
        for (int i = 1; i < n; i++) {
            extra += i * i;
        }
    }

    // --- Recursive branch: LBB0_8 ---
    // If n >= 2, call sum_of_squares(n/2) and add the result.
    if (n >= 2) {
        // In the assembly some shifts are used to compute n/2.
        extra += sum_of_squares(n / 2);
    }

    // --- Final result: LBB0_9 ---
    // The assembly computes: result = n^3 + n + extra.
    return n * n * n + n + extra;
}
