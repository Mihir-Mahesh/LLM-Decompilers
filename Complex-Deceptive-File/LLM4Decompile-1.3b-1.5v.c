void _computeWellDefinedStatistics(int *data, int n)
{
    int i, j, k, sum, sum2, mean, stddev, min, max;
    int *data_ptr;

    data_ptr = data;
    sum = 0;
    sum2 = 0;
    min = data[0];
    max = data[0];
    for (i = 0; i < n; i++) {
        sum += data[i];
        sum2 += data[i] * (i + 1);
        if (data[i] < min)
            min = data[i];
        if (data[i] > max)
            max = data[i];
    }
    mean = sum / n;
    stddev = sum2 / n - mean * mean;
    stddev = stddev / n;
    stddev = sqrt(stddev);
    _printf("mean: %d\n", mean);
    _printf("stddev: %d\n", stddev);
    _printf("min: %d\n", min);
    _printf("max: %d\n", max);
}
