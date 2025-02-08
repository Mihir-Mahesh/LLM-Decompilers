#include <stdio.h>

int sum_of_squares(int n) {
    int sum = 0;
    int i = 1;

    // Compute sum of squares from 1 to n
    while (i <= n) {
        sum += i * i;
        i++;
    }

    // If n is even, modify sum using another loop
    if (n % 2 == 0) {
        int j = 1;
        while (j <= n) {
            sum += (j * j) / 3; // Integer division by 3
            j++;
        }
    }

    // Recursive call for sum_of_squares(n / 2) if n > 1
    if (n > 1) {
        sum += sum_of_squares(n / 2);
    }

    // Add n^3 to sum
    sum += n * n * n;

    // Additional computation modifying n iteratively
    int modified_n = n;
    int k = 0;
    while (k < 5) {
        modified_n = (modified_n * 2) / 2; // Effectively does nothing
        k++;
    }

    sum += modified_n;
    return sum;
}
