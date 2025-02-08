#include <stdio.h>

void processInt(int n) {
    // Part 1: Compute factorial of n
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    printf("Factorial of %d is %llu\n", n, factorial);

    // Part 2: Check if n is prime
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

    // Part 3: Sum digits of factorial
    int digit_sum = 0;
    unsigned long long temp = factorial;
    while (temp > 0) {
        digit_sum += temp % 10;
        temp /= 10;
    }
    printf("Sum of digits in factorial of %d is %d\n", n, digit_sum);
}
