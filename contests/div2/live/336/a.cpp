#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int n, s, f[110], t[110];
  cin>>n>>s;

  for(int i = 1; i <= n; i++)
    cin>>f[i]>>t[i];

  int time = s - f[n] + t[n];
  int temp = time;
  cout<<time<<endl;
  for(int i = n-1; i >= 1; i--)
    {
      if(t[i] >= time + abs(f[i+1] - f[i]))
	{
	  time = t[i];
	  temp =  time;
	}
      
      else if(t[i] > temp)
	{
	  time += abs(f[i] - f[i+1]);
	  temp = time;
	}
      else
	{
	  time += abs(f[i] - f[i+1]);
	  temp = time;
	}
      cout<<time<<endl;
    }
  cout<<(time + f[1])<<endl;
  return 0;
}
