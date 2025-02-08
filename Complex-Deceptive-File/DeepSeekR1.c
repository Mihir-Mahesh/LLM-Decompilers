#include <stdio.h>

void computeWellDefinedStatistics(int *array, int n) {
    int sum = 0;
    int product = 1;
    int weighted_sum = 0;
    
    // First loop: Calculate basic statistics
    for (int i = 0; i < n; i++) {
        sum += array[i];
        product *= (array[i] + 1); // Product of (elements + 1)
        weighted_sum += array[i] * (n - i); // Weighted sum with position
    }
    
    int average = sum / n;
    
    // Second calculation: Adjusted product
    int adjusted_product = product - (weighted_sum % average);
    
    // Second loop: Calculate variance components
    int variance_components = 0;
    for (int i = 0; i < n; i++) {
        int diff = array[i] - average;
        variance_components += diff * diff; // Squared differences
    }
    
    // Final output (note: variance_components isn't used)
    printf("Result: %d\n", adjusted_product);
}
