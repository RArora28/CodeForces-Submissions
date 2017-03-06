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

ll n, k, d1, d2, ans = 0;

void comp1(ll b, ll d) {
  ll temp = k - b*d1 - d*d2;
  ll p1 = temp / 3;
  ll p2 = p1 + b*d1;
  ll p3 = p1 + d*d2;

  if(p1 >= 0 && p2 >= 0 && p3 >= 0 && temp % 3 == 0) {

    ll m = max(p1, max(p2, p3));
    ll u = n-k-(3*m-(p1 + p2 + p3));
    
    if(u >= 0 && (u % 3 == 0))
      ans = 1;
  }
  
  return;
}

int main() {

  ll t;
  
  cin>>t;

  while(t--) {

    cin>>n>>k>>d1>>d2;
    ans = 0;
    //case 1
    comp1(-1, -1);

    //case 2
    comp1(-1, 1);

    //case 3
    comp1( 1, -1);
    
    //case 4
    comp1(1, 1);

    if(ans)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
  
  return 0;
}

