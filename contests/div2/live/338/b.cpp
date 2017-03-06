#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<limits.h>
using namespace std;

int main()
{
  long long int n, m, x, y;
  
  cin>>n>>m;
  long long int dp[n+1];

  for(long long int i = 1; i <= n; i++)
    dp[i] = 1;
  
  vector<set<long long int> >g(n+1);

  for(long long int i = 1; i <= m; i++)
    {
	  cin>>x>>y;
	  g[x].insert(y);
	  g[y].insert(x);
    }
  
  for(long long int i = 2; i <= n; i++)
    {
      //cout<<"no";
      int max = INT_MIN, flag = 0;
      
      for(set<long long int>::iterator it = g[i].begin(); it != g[i].end(); it++)
	{
	  if((*it) > i)
	    break;
	  
	  if(dp[*it] > max)
	    {
	      max = dp[*it];
	      flag = 1;
	    }
	}

      if(flag == 1)
	dp[i] = max + 1;
    }

  long long int max = INT_MIN;
  
  for(long long int i = 1; i <= n; i++)
    {
      dp[i] = dp[i] * g[i].size();

      if(dp[i] > max)
	max = dp[i];
    }

  cout<<max<<endl;
  
  return 0;
}
