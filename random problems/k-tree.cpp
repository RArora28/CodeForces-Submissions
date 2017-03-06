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

LL dp[200][200];

LL DP(LL sum, LL max_edge) { 
  
  if(sum < 0)
    return 0;
  else if(sum == 0)
    return 1;
  else if( dp[sum][max_edge] != -1)
    return dp[sum][max_edge];
  LL Ans = 0;
  LL i;
  rep(i, 1, max_edge + 1) {
    Ans += DP(sum-i, max_edge);
    Ans %= mod;
  }
  
  rep(i, 1, max_edge 
  return dp[sum][max_edge] = Ans;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  LL n, k, d;
  LL i;
  LL j;

  rep(i, 0, 120)
    rep(j, 0, 120)
    dp[i][j] = -1;

  cin>>n>>k>>d;
  
  LL ans = 0;

  rep(i, 1, k+1) { 
    ans += DP(n-i, i);
    ans %= mod;
    trace(ans, i);
  }

  cout<<ans<<endl;

  return 0;
}
