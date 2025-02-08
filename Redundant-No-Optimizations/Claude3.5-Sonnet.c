int sum_of_squares(int n) {
    int result = 0;
    
    // First loop: sum of squares from 1 to n
    for (int i = 1; i <= n; i++) {
        result += i * i;
    }
    
    // If n is even, add squares divided by 3
    if (n % 2 == 0) {
        for (int i = 1; i <= n; i++) {
            result += (i * i) / 3;
        }
    }
    
    // Recursive call for n > 1
    if (n > 1) {
        result += sum_of_squares(n / 2);
    }
    
    // Add cube of n
    result += n * n * n;
    
    // Final transformation on n
    int temp = n;
    for (int i = 0; i < 5; i++) {
        temp *= 2;
        temp /= 2;
    }
    result += temp;
    
    return result;
}
