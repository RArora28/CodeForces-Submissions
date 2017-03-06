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

adjList adj;
int d[300010], dp[300010], taken1[300010], taken2[300010], ch[300010], p[300010];

int children_calc(int v) {

  int ans =  v, maximum = -1;
  int child = 1, temp;
  taken1[v] = 1;

  for(auto it : adj[v])
    if(!taken1[it]) {
      temp = children_calc(it);

      if(temp > maximum) {
	maximum = temp;
	ans = it;
      }
      
      child += temp;
    }
  
  if(maximum >= child / 2) 
    ans = ans;
  else 
    ans = v;
  
  d[v] = ans;

  return ch[v] = child;
}


void dfs(int v) {
  
  taken2[v] = 1;
  
  if(d[v] == v) 
    dp[v] = v;
  else {
    
    int temp = d[v];
    
    while(ch[temp] >= (ch[v]/2))
      temp = d[temp];

    dp[v] = p[temp];
  }

  for(auto it : adj[v])
    if(!taken2[it]) 
      dfs(it);
  
  return;
}

int main() {

  int i, n, q;
  
  cin>>n>>q;

  adj.resize(n+1);
  
  p[1] = 1;
  
  rep(i, 2, n+1) {
    cin>>p[i];

    adj[p[i]].pb(i);
    adj[i].pb(p[i]);
  }

  children_calc(1);
  dfs(1);
  
  while(q--) {
    int x;
    cin>>x;
    cout<<dp[x]<<endl;
  }
  
  return 0;
}

