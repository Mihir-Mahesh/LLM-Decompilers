int sum_of_squares(int n) {
   int result = 0;


   for (int i = 1; i <= n; i++) {
       result += i * i;
   }


   if (n % 2 == 0) {
       for (int i = 1; i <= n; i++) {
           result += (i * i) / 3;
       }
   }


   if (n > 1) {
       result += sum_of_squares(n / 2);
   }


   result += n * n * n;


   int temp = n;
   for (int i = 0; i < 5; i++) {
       temp *= 2;
       temp /= 2;
   }
   result += temp;


   return result;
}
