void _processInt(int n)
{
    unsigned long long fact = 1;
    int i, flag = 1;
    for(i = 1; i <= n; i++)
    {
        fact *= i;
    }
    _printf("Factorial of %d is %llu\n", n, fact);
    if(n > 1)
    {
        for(i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                flag = 0;
                break;
            }
        }
    }
    if(flag)
    {
        _printf("%d is a prime number\n", n);
    }
    else
    {
        _printf("%d is not a prime number\n", n);
    }
    int sum = 0;
    while(fact != 0)
    {
        sum += fact % 10;
        fact /= 10;
    }
    _printf("Sum of digits in factorial of %d is %d\n", n, sum);
}
