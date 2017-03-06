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

LL y, i, j, k, N, M, K, color[110], dp[110][110][110], P[110][110];

int main() { 

  cin>>N>>M>>K;
  
  rep(i, 1, N+1) 
    rep(k, 1, K+1)
    rep(j, 1, M+1)
    dp[i][k][j] = 1e13;
  
  rep(i, 1, N+1)
    cin>>color[i];
  
  rep(i, 1, N+1) 
    rep(j, 1, M+1) 
    cin>>P[i][j];
  
  if(color[1] == 0)
    rep(i, 1, M+1) 
      dp[1][1][i] = P[1][i];
  else 
    dp[1][1][color[1]] = 0;
  
  rep(i, 2, N+1) {
    if(color[i] == 0) { 
      rep(k, 1, K+1) { 
	rep(j, 1, M+1) { 
	  rep(y, 1, M+1) {
	    if(j != y)
	      dp[i][k][j] = min(dp[i][k][j], P[i][j] + dp[i-1][k-1][y]);
	    else 
	      dp[i][k][j] = min(dp[i][k][j], P[i][j] + dp[i-1][k][y]);
	  }
	}
      }
    }
    
    else if(color[i] == color[i-1]) {
      rep(k, 1, K+1) {
	dp[i][k][color[i]] = dp[i-1][k][color[i-1]];
      }
    }

    else if(color[i-1]){ 
      rep(k, 1, K+1) 
	dp[i][k][color[i]] = dp[i-1][k-1][color[i-1]];
    }
    
    else {
      rep(k, 1, K+1)
	rep(j, 1, M+1) 
	{
	  dp[i][k][color[i]] = min(dp[i][k][color[i]], )
    }
  LL A = 1e16;

  rep(i, 1, M+1)
    A = min(A, dp[N][K][i]);
  
  if( A >= 1e13)
    A = -1;
  
  cout<<A<<endl;

  return 0;
}
