#include<stdio.h>
#include<stdlib.h>

int diff(const void *a, const void *b)
{
  long long int i = *(long long int *)a - *(long long int *)b;

  if(i > 0)
    return 1;

  else if(i == 0)
    return 0;
  
  else
    return -1;
}

long long int dp[1000000], a[1000000], count[1000000];

long long int max(long long int a, long long int b)
{
  if(a > b)
    return a;

  else
    return b;
}

long long int f(long long int i)
{
  if(i < 0 || i == 0)
    return 0;

  else if(dp[i] != -1)
   	return dp[i];
  
 else
    {
      dp[i] = max( f(i-1), f(i-2) + i*count[i]);
      return dp[i];
    }
}

int main()
{
  long long int t, i, max = -10;

  scanf("%lld", &t);
  
  for(i = 0; i < t; i++)
    {
      scanf("%lld", &a[i]);
      count[a[i]]++;

      if(a[i] > max)
	max = a[i];
    }


  for(i = 0; i <= max; i++)
    dp[i] = -1;
  
  qsort(a, t, sizeof(long long int), diff);

  count[0] = 0;

  printf("%lld\n",f(max));
    return 0;
  
}












