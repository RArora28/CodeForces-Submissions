#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include <cstring>
using namespace std;

#define mi 1000000007
#define ll long long int
#define rep(i,a,b) for(i=a;i<b;i++)
#define repv(i,a,b) for(i=b-1;i>=a;i--)
#define pair< int,int > ii
#define vector< int > vi
#define vector< pair< int,int > > vii

ll pow1(ll a,ll b)
{
  ll ans=1;
  while(b>0)
    {
      if(b&1)
	{
	  ans=((ans%mi)*(a%mi))%mi;
	}	
      a=((a%mi)*(a%mi))%mi;
      b>>=1;
    }	
  return ans;
}

ll mina(ll arr[],int n)
{
  ll x=arr[0],i;
  int pos=0;
  rep(i,1,n)
    if(arr[i]<x)
      {
	x=arr[i];
	pos=i;
      }
  return x;
}

ll maxa(ll arr[],int n)
{
  ll x=arr[0],i;
  int pos=0;
  rep(i,1,n)
    if(arr[i]>x)
      {
	x=arr[i];
	pos=i;
      }
  return x;
}

int main()
{

  int;
  cin>>;
  cout<<;
  return 0;
}
