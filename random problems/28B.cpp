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

bool taken[200], flag[200];
int V, fav[200], p[200];
adjList adj;

void dfs(int v){
  
  taken[v] = true;
  
  if(v == p[V]) {
    flag[V] = true;
    return;
  }

  for(auto it : adj[v]) 
    if(!taken[it])
      dfs(it);

  return;
  
}

int main() {

  int n, i, j;

  cin>>n;

  adj.resize(n+1);

  rep(i, 1, n+1) 
    cin>>p[i];
  
  rep(i, 1, n+1) 
    cin>>fav[i];

  rep(i, 1, n+1) { 
    rep(j, 1, n+1) { 
      if(i == j)
	continue;
      else if(abs(i-j) == fav[i]) 
	adj[i].pb(j);
    }
  }

  rep(i, 1, n+1) { 

    rep(j, 1, n+1) 
      taken[j] = false;
    
    V = i;
    dfs(i);
  }

  bool ans;

  ans = flag[1];

  rep(i, 2, n+1)
    ans &= flag[i];

  if(ans)
    cout<<"YES"<<endl;
  else 
    cout<<"NO"<<endl;

  return 0;
}

