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

int dp[200][2000];

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int v1, v2, t, d;
  int i, j, k;
  
  cin>>v1>>v2;
  cin>>t>>d;
  
  SET(dp, -1);
  
  dp[1][v1] = 0;
  
  rep(i, 2, t+1) 
    rep(j, 1, 1500) 
    rep(k, max(0, j-d), min(j+d, 1500)+1)
    if(dp[i-1][k] != -1)
      dp[i][j] = max(dp[i][j], dp[i-1][k] + j);

  cout<<dp[t][v2]+v1<<endl;

  return 0;
}
