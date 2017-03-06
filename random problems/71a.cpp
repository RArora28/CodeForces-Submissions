#include<stdio.h>
#include<string.h>

int main() {

  long long int n, m, a;
  
  scanf("%lld %lld %lld", &n, &m, &a);

  if(n % a != 0)
    n = n/a + 1;
  else
    n = n / a;

  if(m % a != 0)
    m = m/a + 1;
  else
    m = m / a;

  printf("%lld\n", m * n);

  return 0;
}

  
