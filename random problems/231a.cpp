#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
  vector<int>v;
  int val, sum1 = 0, sum2 = 0, n, coins = 0, first, last;
  
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++)
    {
      scanf("%d", &val);
      v.push_back(val);
    }

  sort(v.begin(), v.end());

  
  first = -1;
  last = n;
 
  cout<<"no seg till here\n";
  while(first <= last && first >= -1 && last >= 0)
    {
      //cout<<"no seg till here\n";
      if(sum1 >= sum2)
	{
	  last--;
	  sum2 += v[last];
	  coins++;
	}
      else
	{
	  first++;
	  sum1 += v[first];
	}
    }
  
  printf("%d\n", coins);
  return 0;
}
