#include <stdio.h>

void processInt(int n) {
    // Compute n!
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    printf("Factorial of %d is %llu\n", n, factorial);

    // Check for prime:
    // Initialize a flag: non-zero means "prime" (unless n < 2, then it's not prime)
    int isPrime;
    if (n < 2) {
        isPrime = 0;
    } else {
        isPrime = 1;
        // Test divisors from 2 up to sqrt(n)
        for (int j = 2; j * j <= n; j++) {
            if (n % j == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime)
        printf("%d is a prime number\n", n);
    else
        printf("%d is not a prime number\n", n);

    // Sum the digits of the factorial
    int sumDigits = 0;
    unsigned long long temp = factorial;
    while (temp > 0) {
        sumDigits += temp % 10;
        temp /= 10;
    }
    printf("Sum of digits in factorial of %d is %d\n", n, sumDigits);
}
