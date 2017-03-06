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

int coun = 0, thresh;

void rec(int i, int j, int sum) {

  if(sum <= 0)
    return;
  
  else if(i > 10 || j > 10)
    return;
  
  else {

    if(sum >= thresh) {
      coun++;
      rec(i+1, j, (sum-thresh)/2);
      rec(i+1, j+1, (sum-thresh)/2);
    }
  }
  
  return;
}

int main() {

  int i, n, t, j;
  
  cin>>n>>t;
  thresh = pow(2, n);
  
  rec(1,1,t*thresh);
  
  if(coun > n*(n+1)/2)
    coun = n*(n+1)/2;
  
  cout<<coun<<endl;
  
  return 0;
}

