#include <stdio.h>
void computeWellDefinedStatistics(int* arr, int size) {
    int sum = 0;
    int product = 1;
    int weightedSum = 0;
    
    // First pass - calculate sum, product, and weighted sum
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        product *= (arr[i] + 1);
        weightedSum += arr[i] * (size - i);
    }
    
    // Calculate mean
    int mean = sum / size;
    
    // Calculate final result
    int result = product - (weightedSum / mean);
    
    // Calculate variance-like sum
    int variance = 0;
    for (int i = 0; i < size; i++) {
        int diff = arr[i] - mean;
        variance += diff * diff + weightedSum;
    }
    
    printf("Result: %d\n", result);
}
