/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 100005
#define mod 1000000007
#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)
#define INF INT_MAX
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))

//debugging statements
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

LL a[30], A[30][30], X[30];
LL dp[ 1 << 20 ][30];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  LL i, j, n, m, k,x, y, z;

  cin>>n>>m>>k;
  rep(i, 0, n) cin>>a[i];
  rep(i, 0, k) {
    cin>>x>>y>>z;
    A[x-1][y-1] = z;
  }

  X[0] = 1;
  
  rep(i, 1, n+1)
    X[i] = 2*X[i-1];

  rep(i, 0, n)
    dp[X[i]][i] = a[i];

  LL mask;
   
  rep(mask, 0, X[n])
    {
      rep(i, 0, n)
	{
	  if( mask & X[i] )
	    {
	      rep(j, 0, n)
		{
		  if( (mask & X[j]) == 0)
		    {
		      dp[(mask|X[j])][j] = max(dp[(mask|X[j])][j], dp[mask][i] + A[i][j] + a[j]);
		    }
		}
	    }
	}
    }

  LL ans = -1;
  
  rep(mask, 0, X[n])
    {
      LL t = mask, len = 0;

      while(t > 0) {
	if(t & 1)
	  len++;
	t /= 2;
      }

      if(len == m)
	{
	  rep(i, 0, n)
	    {
	      ans = max(ans, dp[mask][i]);
	    }
	}
    }

  cout<<ans<<endl;
  
  return 0;
}
