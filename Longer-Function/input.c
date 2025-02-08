

void processInt(int num) {
   unsigned long long factorial = 1;
   for (int i = 1; i <= num; i++) {
       factorial *= i;
   }
   printf("Factorial of %d is %llu\n", num, factorial);


   int isPrime = 1;
   if (num < 2) {
       isPrime = 0;
   } else {
       for (int i = 2; i * i <= num; i++) {
           if (num % i == 0) {
               isPrime = 0;
               break;
           }
       }
   }
   if (isPrime) {
       printf("%d is a prime number\n", num);
   } else {
       printf("%d is not a prime number\n", num);
   }


   unsigned long long temp = factorial;
   int digitSum = 0;
   while (temp > 0) {
       digitSum += temp % 10;
       temp /= 10;
   }
   printf("Sum of digits in factorial of %d is %d\n", num, digitSum);
}
