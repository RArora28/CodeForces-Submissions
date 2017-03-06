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

ii s[200010];

int main() {

  int i, n, x, y;

  cin>>n;

  rep(i, 0, n) {
    cin>>x>>y;
    s[i].fi = x+y;
    s[i].se = i+1;
    
  }

  sort(s, s + n);

  vi v;

  v.pb(s[n-1].se);

  i = n-2;

  while(s[i].fi == s[i+1].fi) {
    v.pb(s[i].se);
    i--;
  }

  sort(v.begin(), v.end());

  rep(i, 0, v.size())
    cout<<v[i]<<" ";
  cout<<endl;
  
  return 0;
}

