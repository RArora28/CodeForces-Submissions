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


  ll i, n, len;

  char str[100010];

  cin>>str;

   len = strlen(str);
  ll first = 0;
  ll second = 0;
  
  rep(i, 0, len) {
    if(str[i] == 'a')
      first++;
    else
      second++;
  }

  n = len;
  ll total = (n*(n+1)/2)-(first*second);
  
  ll even = 0, evena = 0, odda = 0, evenb = 0, oddb = 0;


  rep(i, 0, len) {
    if(str[i] == 'a') {
      if(i % 2 == 0)
	evena++;
      else
	odda++;
    }

    else if(str[i] == 'b') {
      if(i % 2 == 0)
	evenb++;
      else
	oddb++;
    }

  }
  even = evena * odda + evenb*oddb;
  
  //cout<<total<<endl;
  
  cout<<even<<" "<<total-even<<endl;
    
  return 0;
}

