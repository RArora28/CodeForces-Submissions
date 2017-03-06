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


LL power(LL a, LL b) { 

  LL ans = 1;

  while(b > 0) { 
    if( b & 1) {
      ans *= a % mod;
      ans %= mod;
    }
    a *= a % mod;
    a %= mod;
    b >>= 1;
  }

  return ans % mod;
}

LL c, taken[200010], len[200010];
vector<vector<LL> > adj;

void dfs(LL v) {

  taken[v] = 1;

  for(auto it : adj[v]) {

    if(taken[it] == 0) {
      len[it] = len[v] + 1;
      dfs(it);
    }
    
    else if(taken[it] == 1) {
      c = abs(len[v] - len[it]) + 1;
      taken[v] = 2;
      return;
    }
  }

  taken[v] = 2;
}

int main() { 

  LL n, i;
  LL x;

  cin>>n;

  adj.resize(n+1);

  rep(i, 1, n+1) {
    cin>>x;
    adj[i].PB(x);
  }

  LL ans = 1;
  LL sum = 0;

  rep(i, 1, n+1) { 
    if(!taken[i]) {
      c = 0;
      dfs(i);
      
      if(c > 0) {
	ans *= (power(2, c) % mod  + mod - 2) % mod;
	ans %= mod;
	sum += c;
      }
      
      //trace2(i, ans);
    }
  }

  ans *= power(2, n-sum) % mod;
  ans %= mod;

  cout<<ans<<endl;

  return 0;
}
