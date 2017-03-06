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

int main() {

  int j, i, n, m, start, end;

  cin>>n>>m;

  ii p[m+1];
  
  int fin[n+1], init[n+1];

  for(i = 0; i <= n; i++) {
    fin[i] = 0;
    init[i] = 0;
  }
  rep(i, 1, m+1) {  
    cin>>p[i].fi>>p[i].se;
    init[min(p[i].fi, p[i].se)] = 1;
    fin[max(p[i].fi, p[i].se)] = 1;
  }
  
  end = n;
  start = 1;
  
  rep(i, 1, n+1) { 
    if(fin[i] == 1)
      end = min(i, end);
    if(init[i] == 1)
      start = max(start, i);
  }

  if(start >= end || n == 1) 
    cout<<"0"<<endl;
  else 
    cout<<end-start<<endl;
  return 0;
}

