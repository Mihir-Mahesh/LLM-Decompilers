#include <stdint.h>

// Decompilation of _sum_of_squares from the assembly.
// (Note: The even–loop here adds i*i; although our pseudocode
//  description mentioned computing Q = (i*i*0xAAAAAAABULL)>>33,
//  the assembly’s final addition uses i*i. This conflict has been noted.)
int sum_of_squares(int n) {
    int extra = 0;  // Accumulates the extra values from polynomial, loop, and recursion.

    // Part 1: Base case for nonpositive n.
    if (n <= 0) {
        // For n <= 0, extra remains 0.
        // (Thus f(n) = n^3 + n for n <= 0.)
    }
    else {
        // Part 2: Polynomial Calculation.
        //
        // The assembly computes the following:
        //    A = (n - 1) * (n - 2)
        //    B = (n - 3) * A
        // Then:
        //    partA = A >> 1          (i.e. A divided by 2)
        //    partB = B >> 1          (i.e. B divided by 2)
        //    termB = partB * 0x55555556    (0x55555556 == 1431655766)
        //    poly  = 5 * partA + termB + 4 * n - 3
        //
        // (In many such routines the constant 0x55555556 is used to implement a
        // “magic” division by 3; here it appears that termB is meant to approximate
        // (n-3)*(n-1)*(n-2)/6.)
        int A = (n - 1) * (n - 2);
        int B = (n - 3) * A;
        int partA = A >> 1;  // A/2
        int partB = B >> 1;  // B/2
        int termB = partB * 1431655766;  // Multiply by magic constant.
        int poly = 5 * partA + termB + 4 * n - 3;
        extra += poly;

        // Part 3: Even–Only Summation Loop.
        // The assembly tests the low–order bit of n:
        if ((n & 1) == 0) {  // if n is even...
            //
            // The intended pseudocode (from earlier notes) was:
            //   for (int i = 1; i < n; i++) {
            //       int Q = (int)(((unsigned long long)(i * i) * 0xAAAAAAABULL) >> 33);
            //       extra += Q;
            //   }
            //
            // However, the assembly’s inner loop actually performs:
            //      extra += i * i;
            //
            // (The computed value using the constant and shift appears in rdx
            // but is not added.)
            //
            // We follow the assembly here.
            for (int i = 1; i < n; i++) {
                extra += i * i;
            }
        }

        // Part 4: Recursive Call for n >= 2.
        // The assembly computes a value equivalent to n/2 for positive n and calls
        // sum_of_squares recursively.
        if (n >= 2) {
            int half = n / 2;  // (The assembly computes this as (n + (n>>31)) >> 1.)
            extra += sum_of_squares(half);
        }
    }

    // Part 5: Final Computation.
    // The final result is computed as:
    //      result = n^3 + n + extra
    return n * n * n + n + extra;
}
