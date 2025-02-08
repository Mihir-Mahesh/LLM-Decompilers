#include <stdio.h>

int sum_of_squares(int n) {
    if (n <= 0) {
        return 0;
    }

    // Compute a transformation of n using a product formula
    int temp1 = (n - 1);
    int temp2 = (n - 2) * temp1;
    int temp3 = (n - 3) * temp2;
    temp3 >>= 1; // Divide by 2
    int sum = ((temp3 / 3) + ((temp2 >> 1) * 5 / 3) - 3) + (n * 4 - 3);

    // If n is even, compute additional sum modification
    if (n % 2 == 0) {
        int extra_sum = 0;
        for (int i = 1; i <= n; i += 2) {
            extra_sum += (i * i) / 3 + ((i + 1) * (i + 1)) / 3;
        }
        sum += extra_sum;
    }

    // Recursive call for sum_of_squares(n / 2) if n >= 2
    if (n >= 2) {
        sum += sum_of_squares(n / 2);
    }

    // Add n^3 + n to sum
    sum += (n * n * n) + n;

    return sum;
}
