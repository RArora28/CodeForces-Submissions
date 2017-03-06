/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

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

const int N = 1e5+10;
const int mod = 1e9+7;

LL dp[100];
LL i;

LL rec(LL n, LL k, LL level) {
  if( k == dp[level] + 1|| level == 0)
    return n/2 + n%2;
  else if( k > (dp[level]+1) )
    return n/2 + n % 2 + rec(n/2, k-dp[level]-1, level-1);
  else
    return rec(n/2, k, level-1);
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  LL i, n, l, r;

  cin>>n>>l>>r;

  dp[0] = 0;
  dp[1] = 1;
  
  rep(i, 2, 70)
    dp[i] = 2*dp[i-1]+1;

  LL lg = log2(n);
  LL R = rec(n , r, lg);
  LL L;
  if(l == 1)
  	L = 0;
  
  else L = rec(n, l-1, lg);
  cout<<R - L<<endl;
  
  return 0;
}
