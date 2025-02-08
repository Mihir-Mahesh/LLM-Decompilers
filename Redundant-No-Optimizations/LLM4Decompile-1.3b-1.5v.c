int _sum_of_squares(int n)
{
    int i, j, k, sum = 0;

    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++)
            for (k = j; k <= n; k++)
                sum += i * i + j * j + k * k;

    return sum;
}
