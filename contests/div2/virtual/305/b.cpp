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

ll ans = 0;

void rec(ll start, ll end, ll l, ll r, ll sum) {
  
  if(sum >= l && sum <= r)
    ans++;
  
  else if(sum >= r)
    return;
  
  if(ind > 1) 
    rev(i, ind-10, 1) 
      rec(l, r, ind, sum + c[ind]); 
  
  return;
}

int main() {

  cin>>n>>l>>r>>x;

  rep(i, 0, n)
    cin>>c[i];

  sort(c, c+n);

  rep(i, 0, n) {
    rep(j, i+1, n) {
      if(c[j]-c[i] >= x) {

      }

      ll temp = c[i] + c[j];

      if(temp >= l && temp <= r)
	ans++;
      
    }
  }

  cout<<ans;
  
  return 0;
}

