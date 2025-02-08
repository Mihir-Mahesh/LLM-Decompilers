int _sum_of_squares(int n)
{
  int sum = 0;
  int i;

  for (i = 1; i <= n; i++)
    sum += i * i;

  for (i = 1; i < n; i++)
    sum += (i + 1) * (i + 1) / 3;

  for (i = 1; i < n; i += 2)
    sum += i * i / 3;

  if (n & 1)
    sum += (n + 1) * (n + 1) / 3;

  return sum;
}
