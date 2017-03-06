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

vector<vector<LL> > adj;
LL dp[5000][5000];

void factor(LL n) { 
  
  LL i, j, sq = sqrt(n) + 1;

  rep(i, 1, n+1) 
    for(j = 1; i*j <= n; j++) 
      adj[i*j].PB(i);

  return;
}

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n, k, i, j;

  cin>>n>>k;

  adj.resize(n+10);
  factor(n+8);

 
  rep(i, 1, n+1)
    dp[1][i] = 1;

  rep(i, 2, k+1) { 
    rep(j, 1, n+1) { 
      for(auto it : adj[j]) { 
	dp[i][j] += dp[i-1][it] % mod;
	dp[i][j] %= mod;
      }
    }
  }

  LL ans = 0;

  rep(i, 1, n+1) {
    ans += dp[k][i] % mod;
    ans %= mod;
  }

  cout<<ans<<endl;
  
  return 0;
}
