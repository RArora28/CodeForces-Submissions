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

ll fac[50], inv[50], N, s, f[25], power[25], ans = 0;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll po(ll a, ll b) {

  ll ans = 1;

  while(b > 0) {

    if(b & 1) {
      ans *= a % mod;
      ans %= mod;
    }

    a *= a % mod;
    a %= mod;

    b >>= 1;
  }

  return ans % mod;
}

void precompute() {

  int i;
  
  fac[0] = 1;
  fac[1] = 1;

  rep(i, 2, 100) 
    fac[i] = (i* (fac[i-1] % mod)) % mod;
  
  rep(i, 0, 100)
    inv[i] = po(fac[i], mod-2) % mod;
  
  return;
}

ll com(ll n,ll r) {
  if(r > n)
    return 0;
  
  if((n-r) % mod < r % mod)
    r = n-r;
  
  n %= mod;
  r %= mod;
  
  ll ans=1;
  int i;

  rep(i, 0, r)    {
    ans *= ((n-i) % mod) * inv[i+1];
    ans %= mod;
  }
  
  return ans;
}

void bitmask(int i, ll arr[]) {

  if(i == N+1) {
    
    ll coef = 1;
    ll sum = 0;
    
    rep(i, 1, N+1) 
      if(arr[i]) {
	sum += power[i];
        coef *= -1;
      }
    
    ll temp = s - sum;
    
    if(temp >= 0) {
      ans += coef * (com(N+temp-1, temp) % mod) + mod;
      ans %= mod;
    }
    
    return ;
  }

  arr[i] = 1;
  bitmask(i+1, arr);
  arr[i] = 0;
  bitmask(i+1, arr);
  return;
}


int main() {


  ll i, arr[100];
  
  precompute();

  cin>>N>>s;

  rep(i, 1, N+1) {
    cin>>f[i];
    power[i] = min(f[i], s) + 1 ;
  }
  
  bitmask(1, arr);
  cout<<(ans+mod) % mod<<endl;
  
  return 0;
}

