#include <stdio.h>

int sum_of_squares(int n) {
    int total = 0;
    
    // Part 1: Sum of squares from 1 to n
    for (int i = 1; i <= n; i++) {
        total += i * i;
    }
    
    // Part 2: If n is even, add sum of (i²/3) for 1..n
    if (n % 2 == 0) {
        for (int j = 1; j <= n; j++) {
            total += (j * j) / 3;
        }
    }
    
    // Part 3: Recursive call for n/2 if n > 1
    if (n > 1) {
        total += sum_of_squares(n / 2);
    }
    
    // Part 4: Add n³
    total += n * n * n;
    
    // Part 5: Bit manipulation sequence
    int temp = n;
    for (int k = 0; k < 5; k++) {
        temp = (temp << 1) / 2;  // Equivalent to (temp * 2) / 2
    }
    total += temp;
    
    return total;
}
