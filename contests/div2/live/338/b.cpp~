#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int n, m, x;
  
  cin>>n>>m;

  int a[m+1], flag[m+1], temp = 0;

  
  for(int i = 1; i <= m; i++)
    flag[i] = 0;
  
  for(int i = 1; i <= n; i++)
    {
      cin>>x;
      
      for(int j = 1; j <= x ; j++)
	{
	  cin>>a[j];
	  flag[a[j]] = 1;
	}
    }

  for(int i = 1; i <= m; i++)
    {
      if(flag[i] == 0)
	{
	  temp = 1;
	  break;
	}
    }

  if(temp == 0)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;

  return 0;
}
