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

const int N = 3e5+5;
int dp[N], temp[N];
vector<VII> e;
int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n, m;
  int i, j;
  
  cin>>n>>m;

  e.resize(1e5+5);

  int u, v, w;
  
  rep(i, 1, m+1)
    { 
      cin>>u>>v>>w;
      e[w].PB(MP(u, v));
    }

  rep(i, 1, 1e5+1)
    {
      rep(j, 0, e[i].size())
	{
	  u = e[i][j].F;
	  v = e[i][j].S;
	  temp[u] = 0;
	}

       rep(j, 0, e[i].size())
	{
	  u = e[i][j].F;
	  v = e[i][j].S;
	  temp[v] = max(temp[v], dp[u]+1);;
	}
        rep(j, 0, e[i].size())
	{
	  u = e[i][j].F;
	  v = e[i][j].S;
	  dp[v] = max(dp[v], temp[v]);
	}
    }

  int ans = -1;

  rep(i, 1, n+1)
    ans = max(ans, dp[i]);

  cout<<ans<<endl;
  
  return 0;
}
