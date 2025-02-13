#include <stdint.h>

//--------------------------------------------------------------------
// Helper function for the “magic division” used in the assembly.
// This implements the pattern: (x * magic_const) >> 33.
// (Assembly uses the constant 0xAAAAAAAB, i.e. 2863311531.)
static inline uint32_t magic_divide_33(uint32_t x) {
    return (uint32_t)(((uint64_t)x * 2863311531ULL) >> 33);
}

//--------------------------------------------------------------------
// Decompilation of _sum_of_squares:
//
// Overview of the function’s parts (with references to the assembly):
//
// 1. Function Prologue and Parameter Setup (assembly %bb.0):
//      - Save registers, copy input 'n' (from %edi) into a local variable (r14).
//
// 2. Base Case Check (branch LBB0_1):
//      - If n <= 0, set correction (ebx) to 0.
// 
// 3. Baseline Correction Computation (assembly %bb.2):
//      - Compute A = (n-1)*(n-2)
//      - Compute B = (n-3)*A
//      - Compute part1 = (B >> 1) * 0x55555556  (magic multiply simulating a division)
//      - Compute part2 = 5*(A >> 1)
//      - Combine these and add (4*n - 3) to get an initial “correction” stored in ebx.
//
// 4. Even-n Adjustments (branches LBB0_3–LBB0_8):
//      - The assembly tests the parity (testb $1, %r14b).
//      - For even n (n & 1 == 0) only, it enters an inner loop.
//      - In that loop, for counter (esi) running from 1 until n-1,
//        it computes corrections using magic division on (counter)² and (counter+1)²
//        and adds these into ebx.
//      - (Note: For n == 1 the assembly would take a special branch,
//       but since 1 is odd the even-adjustment code is skipped.)
//
// 5. Recursive Accumulation (branch LBB0_10):
//      - If n >= 2, recursively call sum_of_squares(n >> 1) (i.e. n/2)
//        and add that result into ebx.
//
// 6. Final Combination (branch LBB0_11):
//      - Compute n³ + n and then add ebx, then return that as the final result.
//
// The following C code reproduces that logic.
 
uint64_t sum_of_squares(uint32_t n) {
    uint64_t correction = 0;  // corresponds to register ebx in assembly

    // (1) Base Case Check – if n <= 0, no further correction.
    if (n <= 0) {
        correction = 0;
    } else {
        // (2) Baseline Correction Computation.
        // Assembly LBB0_2:
        //   eax = n-1; ecx = n-2; ecx = (n-1)*(n-2)
        //   eax = n-3; eax = (n-3)*(n-1)*(n-2)
        //   Then:
        //      part1 = ( (n-3)*(n-1)*(n-2) >> 1 ) * 0x55555556
        //      part2 = 5 * ( ((n-1)*(n-2)) >> 1 )
        //      combined = part1 + part2, then add (4*n - 3)
        uint32_t A = (n - 1) * (n - 2);
        uint32_t B = (n - 3) * A;
        uint32_t part1 = ((B >> 1) * 1431655766u);  // 0x55555556 = 1431655766
        uint32_t part2 = 5 * (A >> 1);
        uint32_t combined = part1 + part2;
        correction = (uint64_t)combined + 4 * n - 3;

        // (3) Even–n Adjustments.
        // The assembly tests: testb $1, %r14b and jumps to LBB0_9 if n is odd.
        // Therefore, we perform further adjustments only if n is even.
        if ((n & 1) == 0) {
            // For even n (n != 1 is implicit, because 1 is odd):
            // Setup a counter (esi) and a loop variable.
            // In the assembly, ecx is set to (-n) (via "movl %r8d, %ecx" and "subl %r14d, %ecx").
            // The loop continues until (2 + (-n) + counter) equals 1,
            // which is equivalent to counter != n - 1.
            uint32_t counter = 1;
            while (counter != n - 1) {
                // For the current counter, compute:
                //   temp1 = magic_divide_33(counter^2)
                // and for counter+1:
                //   temp2 = magic_divide_33((counter+1)^2)
                uint32_t temp1 = magic_divide_33(counter * counter);
                uint32_t temp2 = magic_divide_33((counter + 1) * (counter + 1));
                // Add both to the correction.
                correction += temp1 + temp2;
                counter += 2;
            }
        }

        // (4) Recursive Accumulation.
        // Assembly LBB0_10: If n >= 2, call sum_of_squares(n >> 1) and add its result.
        if (n >= 2) {
            correction += sum_of_squares(n >> 1);
        }
    }

    // (5) Final Combination.
    // Assembly LBB0_11 computes: result = n * n * n + n + correction.
    uint64_t result = (uint64_t)n * n * n + n + correction;
    return result;
}