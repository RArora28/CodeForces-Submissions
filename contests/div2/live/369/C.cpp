/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;
typedef vector<VI> adjList;

#define mod 1000000007
#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = b; i > a; i--)
#define REP(i, n) for(i = 1; i <= n; i++)
#define pr0(arr, n) rep(i, 0, n) cout<<arr[i]<<" "; cout<<endl;
#define pr1(arr, n) rep(i, 1, n+1) cout<<arr[i]<<" "; cout<<endl;
#define INF INT_MAX
#define gc getchar_unlocked
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))
#define gu getchar
#define pu putchar
#define SI(n) scanf("%d",&n)
#define PI(n) printf("%d\n",n)
#define SLL(n) scanf("%lld",&n)
#define PLL(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//fast io using cin/cout
//ios::sync_with_stdio(false);	cin.tie(NULL);

LL n, K, m, dp[110][110][110], color[110], P[110][110];

LL f(LL p, LL k, LL next) { 

  if(p == 0 && k == 0) 
    return 0;
  
  else if((p == 0 && k != 0) || k < 0) 
    return 1e16;
	  
  else if(dp[p][k][next] != -1)
    return dp[p][k][next];
  
  else if(color[p] != 0) {
    if(color[p] == next)
      dp[p][k][next] = f(p-1, k, next);
    else
      dp[p][k][next] = f(p-1, k-1, color[p]);
  }
  
  else {
    LL Ans = 1e16;
    LL j;
    
    rep(j, 1, m+1) {
      if(j != next) 
	Ans = min(Ans, P[p][j] + f(p-1, k-1, j));
      else  
	Ans = min(Ans, P[p][j] + f(p-1, k, j));
    }
    
    return dp[p][k][next] = Ans;
  }
}

int main() { 
  
  LL i, j, k;
  LL ktemp = 1;
  bool ok = true;
  
  rep(i, 1, 110)  
    rep(j, 1, 110) 
    rep(k, 1, 110) 
    dp[i][j][k] = -1;
  
  cin>>n>>m>>K;

  rep(i, 1, n+1) {
    cin>>color[i];
    if(color[i] == 0)
      ok = false;
  }

  rep(i, 1, n+1) 
    rep(j, 1, m+1)
    cin>>P[i][j];
  
  rep(i, 2, n+1)
    if(color[i] != color[i-1])
      ktemp++;

  if(ok) {
    if(ktemp != K)
      cout<<"-1"<<endl;
    else 
      cout<<"0"<<endl;
    return 0;
  }
  
  LL Ans = 1e16;

  if(color[n] != 0)
    Ans = f(n-1, K-1, color[n]);

  else     
    rep(i, 1, m+1)
      Ans = min(Ans, P[n][i] + f(n-1, K-1, i));
  
  if(Ans >= 1e16)
    Ans = -1;
  
  rep(i, 1, n+1)  
    rep(j, 1, K+1) 
    rep(k, 1, m+1)
    trace4(i, j, k, dp[i][j][k]);
    cout<<Ans<<endl;

  return 0;
}
