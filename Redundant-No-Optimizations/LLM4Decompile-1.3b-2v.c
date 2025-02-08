int _sum_of_squares(int n)
{
  int i, j, k, l, m, sum;

  sum = 0;
  for (i = 1; i <= n; i++)
    sum += i * i;

  if (n % 2 == 0)
    for (j = 1; j <= n; j++)
      sum += j * j / 3;

  if (n > 1)
    sum += _sum_of_squares(n / 2);

  m = n;
  for (k = 0; k < 5; k++)
    m = (m << 1) / 2;

  return sum + m * m * m;
}
