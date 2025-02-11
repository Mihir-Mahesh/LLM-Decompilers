int sum_of_squares(int n) {
    if (n <= 0) {
        return 0;
    }
    
    // Initial calculations
    int result = 0;
    
    // Optimized calculation for large numbers
    long long temp1 = (n - 1) * (n - 2);
    long long temp2 = (n - 3) * temp1;
    temp2 >>= 1;  // Divide by 2
    int part1 = (temp2 * 1431655766) >> 32;  // Magic number division
    temp1 >>= 1;
    int part2 = temp1 * 5;
    result = part1 + part2 + (n * 4) - 3;
    
    // Special handling for even numbers
    if (!(n & 1)) {  // If n is even
        if (n > 0) {
            for (int i = 1; i <= n; i++) {
                result += (i * i) / 3;
            }
        }
    }
    
    // Recursive part for n >= 2
    if (n >= 2) {
        result += sum_of_squares(n >> 1);  // Recursive call with n/2
    }
    
    // Final calculation
    result += n * n * n + n;
    
    return result;
}
