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

int n, m ,dis[20010];
adjList adj;

void dfs(int v) { 
  
  for(auto it : adj[v]) { 
    if(dis[v] + 1 < dis[it]) { 
      dis[it] = dis[v] + 1;
      dfs(it);
    }
  }

  return;
}

int main() { 

  int i;
  
  cin>>n>>m;

  adj.resize(2e4+1);
  
  adj[1].pb(2); 
  dis[1] = INT_MAX;
  
  rep(i, 2, 2*max(m, n)+1) {
    
    dis[i] = INT_MAX;

    if(i <= m) { 
      adj[i].pb(2*i);
      adj[i].pb(i-1);
    }
    
    else 
      adj[i].pb(i-1);
  }
  
  rep(i, 1, 2e4 + 1) 
    dis[i] = INT_MAX;
  
  dis[n] = 0;
  
  dfs(n);

  // rep(i, 1, n+1)
  //   cout<<dis[i]<<endl;

  cout<<dis[m]<<endl;
  
  return 0;
}

