#include <stdio.h>

void processInt(int n) {
    // Calculate factorial
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    printf("Factorial of %d is %llu\n", n, factorial);
    
    // Check if number is prime
    int isPrime = 1;
    if (n < 2) {
        isPrime = 0;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }
    
    if (isPrime) {
        printf("%d is a prime number\n", n);
    } else {
        printf("%d is not a prime number\n", n);
    }
    
    // Calculate sum of digits in factorial
    unsigned long long temp = factorial;
    int sumOfDigits = 0;
    while (temp > 0) {
        sumOfDigits += temp % 10;
        temp /= 10;
    }
    printf("Sum of digits in factorial of %d is %d\n", n, sumOfDigits);
}
