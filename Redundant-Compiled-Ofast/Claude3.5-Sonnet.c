int sum_of_squares(int n) {
    if (n <= 0) {
        return 0;
    }
    
    // Initial calculation using optimized arithmetic
    long long temp1 = (n - 1) * (n - 2);
    long long temp2 = (n - 3) * temp1;
    temp2 = temp2 >> 1;
    int result = (temp2 * 1431655766) >> 32;  // Optimized division
    
    temp1 = temp1 >> 1;
    int temp3 = temp1 * 5;
    result += temp3;
    result += (n * 4) - 3;
    
    // Recursive part
    if (n >= 2) {
        result += sum_of_squares(n >> 1);  // n/2 using bit shift
    }
    
    // Final calculations
    result += (n * n * n) + n;
    
    return result;
}
