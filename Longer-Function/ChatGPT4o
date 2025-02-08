#include <stdio.h>

void processInt(int n) {
    // Compute factorial
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    printf("Factorial of %d is %llu\n", n, factorial);

    // Check if n is prime
    int is_prime = 1;
    if (n < 2) {
        is_prime = 0;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }
    if (is_prime) {
        printf("%d is a prime number\n", n);
    } else {
        printf("%d is not a prime number\n", n);
    }

    // Compute sum of digits in factorial
    unsigned long long temp = factorial;
    int sum_of_digits = 0;
    while (temp > 0) {
        sum_of_digits += temp % 10;
        temp /= 10;
    }
    printf("Sum of digits in factorial of %d is %d\n", n, sum_of_digits);
}
