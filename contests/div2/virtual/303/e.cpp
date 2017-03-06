#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ii pair<long long int, long long int>
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

vector<vector<pair<ll, ll > > >adj;
ll parent[300010], dis[300010], n, enter[300010];

void shortest_path(ll source) {

  ll i;
  
  dis[source] = 0;
  
  priority_queue<ii, vector<ii>, greater<ii> > p;
  
  p.push(mp(0, source));
  
  while(!p.empty()) {

    ii T = p.top();
    ll d = T.fi;
    ll curr = T.se;
    p.pop();
    
    if(d > dis[curr])
      continue;
    
    for(auto it : adj[curr]) {
      if(dis[curr] + it.fi <= dis[it.se]) { 
	if(it.fi < enter[it.se]) {
	  enter[it.se] = it.fi;
	  parent[it.se]= curr;
	  dis[it.se] = dis[curr] + it.fi;
	  p.push(mp(dis[it.se], it.se));
	}
      }
    }
  }

  return;
}

int main() { 

  ll max_val = 1e18;
  map<ii, ll> ma;
  ll m, i;

  ll u, v, w;

  cin>>n>>m;
    
  rep(i, 1, n+1) {
    dis[i] = max_val;
    enter[i] = max_val;
  }

  adj.resize(n+1);

  rep(i, 1, m+1) {
    cin>>u>>v>>w;
    ma[ii(u, v)] = i;
    ma[ii(v, u)] = i;
    adj[u].pb(mp(w, v));
    adj[v].pb(mp(w, u));
  }
  
  ll source;
  cin>>source;
  
  shortest_path(source);
  ll sum = 0;
  
  rep(i, 1, n+1) 
    if(enter[i] != max_val)
      sum += enter[i];
  
  cout<<sum<<endl;
  
  rep(i, 1, n+1) 
    if(enter[i] != max_val)
      cout<<ma[ii(i, parent[i])]<<" ";
  
  cout<<endl;

  return 0; 
}

