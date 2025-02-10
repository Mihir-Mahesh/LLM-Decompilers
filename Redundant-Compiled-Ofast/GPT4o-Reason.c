#include <stdint.h>
#include <stdio.h>

// Note: The names of local variables and the structure of the code are chosen
// to mimic the assembly. The arithmetic using magic constants is preserved verbatim.
// The behavior of the original function is rather obscure.

int sum_of_squares(int n) {
    int acc;           // will eventually hold the extra accumulated value (in ebx)
    int r14 = n;       // r14 holds the original argument n

    if (n <= 0) {
        // LBB0_1: For nonpositive n, set acc = 0.
        acc = 0;
        goto LBB0_11;
    }

    // LBB0_2: Compute an initial value for acc.
    {
        int a = n - 1;
        int b = n - 2;
        int64_t prod1 = (int64_t)a * b;              // (n-1)*(n-2)
        int c = n - 3;
        int64_t prod2 = c * prod1;                   // (n-3)*(n-1)*(n-2)
        prod2 = prod2 >> 1;                          // divide by 2

        // Use a “magic‐number” to compute (roughly) division by 3.
        int part1 = (int) prod2;                     // lower 32 bits of ((n-3)*(n-1)*(n-2))/2
        part1 = (int)((int64_t)part1 * 1431655766LL);  // multiply by 0x55555556

        // Also compute 5 * ((n-1)*(n-2)/2).
        int part2 = ((n - 1) * (n - 2)) >> 1;
        part2 = 5 * part2;

        // Combine the two pieces.
        int temp = part1 + part2;
        // Compute: acc = 4*n + temp - 3.
        acc = 4 * n + temp - 3;
    }

    // Test if n is odd.
    if (n & 1)
        goto LBB0_9;

    // LBB0_3 ... LBB0_7: This branch is taken for even n (with n != 1).
    {
        int r8 = n & 1;   // For even n, r8 is 0.
        if (n != 1) {
            int ecx = r8 - n;   // ecx becomes -n.
            int esi = 1;
            const int edx = 2863311531;  // 0xAAAAAAAB

            // LBB0_6: Loop until (2 + ecx + esi) == 1.
            while ((2 + ecx + esi) != 1) {
                // Compute: part1 = ((esi * esi) * edx) >> 33, then add current acc.
                int edi = esi;
                edi *= esi;
                {
                    uint64_t prod = (uint64_t) edi * (uint64_t) edx;
                    edi = (int)(prod >> 33);
                }
                edi += acc;

                // Compute: part2 = (((esi+1) * (esi+1)) * edx) >> 33.
                int t = esi + 1;
                t *= t;
                int part2;
                {
                    uint64_t prod = (uint64_t) t * (uint64_t) edx;
                    part2 = (int)(prod >> 33);
                }
                // Update acc.
                acc = edi + part2;

                // Increment esi by 2.
                esi += 2;
            }
        }
    }

LBB0_7:
    {
        // If n was odd then r8 (n & 1) is nonzero.
        int r8 = n & 1;
        if (r8) {
            // LBB0_8: Do one extra “adjustment.”
            // (The assembly multiplies a register by itself, applies the magic constant,
            // shifts right 33, and adds the result to acc.)
            int edi = 0;  // (Value of edi here is ambiguous; we use 0 as a placeholder.)
            edi *= edi;
            {
                uint64_t prod = (uint64_t) edi * 2863311531ULL;
                int temp = (int)(prod >> 33);
                acc += temp;
            }
        }
    }

LBB0_9:
    // LBB0_10: For n >= 2, recursively add sum_of_squares(n >> 1).
    if (n >= 2) {
        int rec = sum_of_squares(n >> 1);
        acc += rec;
    }

LBB0_11:
    {
        // LBB0_11: Final computation.
        // Compute n^3 + n and then add the accumulated value in acc.
        int result = n * n;      // n^2
        result = result * n;     // n^3
        result += n;             // n^3 + n
        result += acc;           // n^3 + n + acc
        return result;
    }
}
