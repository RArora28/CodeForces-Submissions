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

const int N = 5e6+10;
const int mod = 1e9+7;

bool isPrime[N];
int dp[N], g[N];

void solve(int n)
{
  int i, j, temp = sqrt((n)+1);
  rep(i, 2, temp+1)
    if(!isPrime[i])
      {
	for(j = 2; i*j <= n; j++)
	  {
	    isPrime[i*j] = true;
	    g[i*j] = i;
	  }
      }
  rep(i, 2, n+1)
    if(!isPrime[i])
      dp[i] = 1;
    else dp[i] = 1 + dp[i/g[i]];
  rep(i, 1, n+1)
    dp[i] += dp[i-1];
  return;
}
#define Sll(x) scanf("%d", &x)

int main() {
  int t; cin>>t;
  solve(5e6+2);
  int a, b;
  while(t--)
    {
      Sll(a); Sll(b);
      printf("%d\n", dp[a]-dp[b]);
    }
  return 0;
}
