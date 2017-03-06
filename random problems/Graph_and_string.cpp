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
char str[1000];
bool flag = true, taken1[1000], taken2[1000];

void dfs1(int v) { 

  str[v] = 'a';
  taken1[v] = true;
  
  for(auto it : adj[v]) 
    if(!taken1[it] && str[it] == 'd')
      dfs1(it);
  
  return;
}

void dfs2(int v) { 

  str[v] = 'c';
  taken2[v] = true;

  for(auto it : adj[v]) 
    if(!taken2[it] && str[it] == 'd')
      dfs2(it);

  return;
}

int main() { 

  int i, a, b;
  int n, m;

  cin>>n>>m;
  
  rep(i, 1, n+1)
    str[i] = 'd';

  adj.resize(n+1);

  rep(i, 1, m+1) { 
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  rep(i, 1, n+1) 
    if(adj[i].size() == n-1) 
      str[i] = 'b';
  
  rep(i, 1, n+1)
    if(str[i] == 'd') {
      dfs1(i);
      break;
    }

  rep(i, 1, n+1)
    if(str[i] == 'd') {
      dfs2(i);
      break;
    }

  rep(i, 1, n+1) 
    if(str[i] == 'd') {
      flag = false;
      break;
    }

  if(!flag) 
    cout<<"No"<<endl;
  else { 
    cout<<"Yes"<<endl;
    
    rep(i, 1, n+1) 
      cout<<str[i];
    
    cout<<endl;
  }

  return 0;
}

