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
#define adjList vector<vector<pair<long long int, long long int> > >
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
ll dis[100010];

void shortest(ll source, ll n) { 

  ll i;

  rep(i, 1, n+1)
    dis[i] = 1e10;

  dis[source] = 0;

  priority_queue<ii, vector<ii>, greater<ii> > p;

  p.push(mp(0, source));

  while(!p.empty()) { 

    ii T = p.top();
    p.pop();
    ll d = T.fi;
    ll curr = T.se;

    if(d > dis[curr]) continue;
    
    for(auto it : adj[curr])
      if(dis[curr] + it.fi < dis[it.se]) { 
	dis[it.se] = dis[curr] + it.fi;
	p.push(mp(dis[it.se], it.se));
      }
  }

  return;
}
int main() {

  ll n, m;
  ll i;

  cin>>n;
  
  adj.resize(n+1);

  ll a, b, w, total = 0;
  
  m = n-1;

  while(m--) { 
    cin>>a>>b>>w;

    adj[a].pb(mp(w, b));
    adj[b].pb(mp(w, a));
    
    total += w;
  } 

  total *= 2;
  
  shortest(1, n);
  
  ll Max = -1;
  
  rep(i, 2, n+1) {
    //   cout<<dis[i]<<endl;
    Max = max(dis[i], Max);
  }

  if(n == 1)
    cout<<"0"<<endl;
  else 
    cout<<(total - Max)<<endl;

  return 0;
}

