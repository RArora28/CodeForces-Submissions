#include<iostream>
#include<stdio.h>

long long int dp[1000010];

long long int LIS(long long int a[], long long int n)
{

  dp[0] = 1;
  
  for(long long int i = 1; i < n; i++)
    {
      for(long long int j = 0; j <= i - 1; j++)
	{
	  if(a[i] > a[j])
	    {
	      long long int temp = dp[j] + 1;

	      if(temp > dp[i])
		dp[i] = temp;
	    }
	  
	  else
	    dp[i] = 1;
	}
    }

  long long int max = dp[0];

  for(long long int i = 1; i < n; i++)
    {
      if(dp[i] > max)
	max = dp[i];
    }

  return max;
}

int main()
{
  long long int n, a[1000010];
  
  scanf("%lld", &n);

  for(int i = 0; i < n; i++)
    scanf("%lld", &a[i]);

  printf("%lld\n", n - LIS(a, n));

  return 0;
}
