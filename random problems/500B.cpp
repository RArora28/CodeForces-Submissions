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

char A[310][310];
int P[310], V, P1[310];
bool taken[310];
adjList adj;
set<int> s1, s2;
vi v1, v2;

void dfs(int v) { 
  
  taken[v] = true;
  v1.pb(v);
  v2.pb(P[v]);

  for(auto it : adj[v]) 
    if(!taken[it])
      dfs(it);
      
  return;
}

int main() { 
  
  int n, i, j;

  cin>>n;

  rep(i, 1, n+1) 
    cin>>P[i];

  adj.resize(n+1);

  rep(i, 1, n+1) 
    rep(j, 1, n+1)  { 
    
    cin>>A[i][j];
    
    if(A[i][j] == '1' && i != j) 
      adj[i].pb(j);
  }
  
  rep(i, 1, n+1) {
    
    if(!taken[i]) {
      v1.clear();
      v2.clear();
      dfs(i);
      
      sort(v1.begin(), v1.end());
      sort(v2.begin(), v2.end());

      rep(j, 0, v1.size())
	P1[v1[j]] = v2[j];
    }
  }
  
  rep(i, 1, n+1) 
    cout<<P1[i]<<" ";

  cout<<endl;

  return 0;
}

