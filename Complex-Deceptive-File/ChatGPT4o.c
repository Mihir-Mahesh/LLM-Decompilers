#include <stdio.h>

void computeWellDefinedStatistics(int *arr, int n) {
    int sum = 0;
    int product = 1;
    int variance_term = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        product *= (arr[i] + 1);
        variance_term += arr[i] * (n - i);
    }
    
    int mean = sum / n;
    int adjusted_value = product - (variance_term / mean);

    int variance = 0;
    for (int i = 0; i < n; i++) {
        int diff = arr[i] - mean;
        variance += diff * diff;
    }

    printf("Result: %d\n", adjusted_value);
}
