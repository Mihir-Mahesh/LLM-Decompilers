#include <stdio.h>

int sum_of_squares(int n) {
    int acc = 0;
    int i, j, idx;
    
    // --- First Loop ---
    // For i from 1 to n, add i*i.
    for (i = 1; i <= n; i++) {
        acc += i * i;
    }
    
    // --- Even n branch ---
    // Check if n is even (i.e. n mod 2 equals 0).
    if ((n % 2) == 0) {
        // For j from 1 to n, add (j*j)/3 (using integer division).
        for (j = 1; j <= n; j++) {
            acc += (j * j) / 3;
        }
    }
    
    // --- Recursive call ---
    // If n is greater than 1, recursively add the result for n/2.
    if (n > 1) {
        acc += sum_of_squares(n / 2);
    }
    
    // --- Add n^3 ---
    acc += n * n * n;
    
    // --- Second Loop (Dummy loop) ---
    // Set tmp to n and perform a loop 5 times:
    // Each iteration multiplies tmp by 2 then divides by 2.
    // For positive integers, this leaves tmp unchanged.
    int tmp = n;
    for (idx = 0; idx < 5; idx++) {
        tmp = tmp << 1;  // Multiply by 2.
        tmp = tmp / 2;   // Divide by 2.
    }
    // Add tmp (which is still n) to acc.
    acc += tmp;
    
    return acc;
}
