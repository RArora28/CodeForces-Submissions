#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define adjList vector<vector<int> >
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, z, q) for(i = z; i < q; i++)
#define rev(i, z, q) for(i = z; i > q; i--)

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll a,ll b) {
  ll ans = 1;  
  while(b > 0){
    if(b & 1)
      ans = ((ans % mod) *(a % mod)) % mod;
    a=((a % mod)*(a % mod)) % mod;
    b >>= 1;
  }
  return ans;
}

int dp[400][400], p;
vii temp;
vector<vii> g;

int dfs(int v, int i, int j) {

  if(v == p)
    return 0;
  
  else if(dp[i][j] != -1)
    return dp[i][j];

  else {
    
    int m = INT_MAX, sum;

    for(vii::iterator it = g[v].begin(); it !=g[v].end(); it++)  {
      sum = abs(i-(*it).fi) + abs(j-(*it).se) + dfs(v+1, (*it).fi, (*it).se);
      m = min(m, sum);
    }

    return dp[i][j] = m;
  }
}


int main() {

  int n, m, i, j, x;

  cin>>n>>m>>p;

  g.resize(p+1);
  
  memset(dp, -1, sizeof(dp));
  
  rep(i, 1, n+1) {
    rep(j, 1, m+1) {
      cin>>x;

      // if(x == 1)
      // 	temp.pb(mp(i, j));
      // else if(x > 1) 
      g[x-1].pb(mp(i, j));
    }
  }
  
  int ans = INT_MAX;
  
  cout<<dfs(0, 1, 1)<<endl;

//cout<<ans<<endl;
  
  return 0;
}

