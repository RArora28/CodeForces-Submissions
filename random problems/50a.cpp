#include<stdio.h>

int main()
{
  int m, n, temp;
  scanf("%d %d", &m, &n);
  printf("%d\n", ((m - m % 2) * (n - n % 2) + (n - 1) * (m % 2) + (m - 1) * (n % 2) + 1) / 2);
  return 0;
}
