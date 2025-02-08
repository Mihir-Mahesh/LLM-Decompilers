int _sum_of_squares(int n)
{
    int sum = 0;
    int i;

    for (i = 1; i <= n; i++)
        sum += i * i;

    return sum;
}
