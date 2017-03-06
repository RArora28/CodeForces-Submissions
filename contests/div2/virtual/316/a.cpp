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

  int n, m;

  cin>>n>>m;

  int ans = 1 ,j, i;
  int a[n+2][m+2], winner[n+2] , ma = -1;

  memset(winner, 0, sizeof(winner));
  
  rep(i, 1, m+1) 
    rep(j, 1, n+1) 
      cin>>a[i][j];

  rep(i, 1, m+1) {

    ma = a[i][1];
    ans = 1;
    
    rep(j, 2, n+1) {

      if(a[i][j] > ma) {
	ma = a[i][j];
	ans = j;
      }
      
    }
    
    winner[ans]++;
  }
  
  ans = 1;
  ma = winner[1];
  
  rep(i, 2, n+1) 
    if(winner[i] > ma) {
      ma = winner[i];
      ans = i;
    }

  cout<<ans<<endl;
  
  return 0;
}

