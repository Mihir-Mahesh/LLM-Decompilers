void _computeWellDefinedStatistics(int *data, int n)
{
    int i, sum, prod, mean, var, std;
    sum = 0;
    prod = 1;
    mean = 0;
    for (i = 0; i < n; i++) {
        sum += data[i];
        prod *= (data[i] + 1);
        mean += (data[i] * (n - i));
    }
    var = prod - (mean / n);
    std = (int) sqrt(var);
    _printf("Result: %d\n", var);
}
