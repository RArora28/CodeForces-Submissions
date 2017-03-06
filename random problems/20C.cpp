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
#define vll vector<pair<long long int,long long  int> >
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

vector<vll> adj;
ll parent[200010], dis[200010], n, m, i, j;

void dijkstra(ll source) { 

  rep(i, 1, n+1) {
    parent[i] = i;
    dis[i] = 1e13;
  }
  
  dis[source] = 0;
  
  priority_queue<pair<ll, ll>, vector<pair<ll, ll > >, greater<pair<ll, ll> > > p;
  
  p.push(mp(0, source));
  
  while(!p.empty()) { 
    
    pair<ll, ll> t = p.top();
    ll d = t.fi;
    ll curr = t.se;
    p.pop();
    
    if(d > dis[curr]) continue;
    
    for(auto it : adj[curr]) 
      if(dis[curr] + it.fi < dis[it.se]) {
	dis[it.se] = dis[curr] + it.fi;
	parent[it.se] = curr;
	p.push(mp(dis[it.se], it.se));
      }
  }
  
  return;
}

void print(ll v) { 

  if(v == parent[v]) {
    cout<<v<<" ";
    return;
  }
  
  print(parent[v]);
  cout<<v<<" ";
  return;
}

int main() { 
  
  ll a, b, w;

  cin>>n>>m;

  adj.resize(n+1); 
  
  while(m--) { 
    cin>>a>>b>>w;
    adj[a].pb(ii(w, b));
    adj[b].pb(ii(w, a));
  }

  dijkstra(1);

  if(dis[n] != 1e13)
    print(n);
  else 
    cout<<"-1";
  
  cout<<endl;
  
  return 0;
}

