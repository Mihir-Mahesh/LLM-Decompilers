void _processInt(int n)
{
    int i, j, k, l;
    long m, t;
    char s[100];

    i = n;
    m = 1;
    j = 1;
    while (j <= i) {
        m *= j;
        j++;
    }
    _printf("%d = %ld\n", i, m);

    k = 1;
    while (k <= i) {
        if (i % k == 0) {
            _printf("%d = %d\n", i, k);
            return;
        }
        k++;
    }
    _printf("%d is prime\n", i);

    t = m;
    l = 0;
    while (t > 0) {
        l = l + t % 10;
        t = t / 10;
    }
    if (l == 0) {
        _printf("%d is a palindrome\n", i);
    } else {
        _printf("%d is not a palindrome\n", i);
    }
}
