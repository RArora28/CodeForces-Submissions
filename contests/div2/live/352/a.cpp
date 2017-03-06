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

  int i, k;

  vi v;
  
  for(i = 0; i < 500; i++) {

    int temp= i;

    vi v1;
    
    while(temp > 0) {
      v1.pb(temp % 10);
      temp /= 10;
    }

    rev(k, v1.size()-1, -1)
      v.pb(v1[k]);
  }

  //rep(i, 0, v.size())
  //cout<<v[i];
  int n;
  cin>>n;
  
  cout<<v[n-1]<<endl;
  return 0;
}

