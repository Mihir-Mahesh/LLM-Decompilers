void computeWellDefinedStatistics(int* data, int size) {
   int sum = 0;
   int product = 1;
   int temp = 0;


   for (int i = 0; i < size; i++) {
       sum += data[i];
       product *= (data[i] + 1);
       temp += data[i] * (size - i);
   }


   int average = sum / size;
   int adjustedProduct = product - temp % average;


   for (int i = 0; i < size; i++) {
       temp += (data[i] - average) * (data[i] - average);
   }


   printf("Result: %d\n", adjustedProduct);
}
