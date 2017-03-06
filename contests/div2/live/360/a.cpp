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


ll a[100010];

int main() {

  int i, n, j;
  int d;
  char str[150];

  cin>>n;
  cin>>d;
  
  rep(i, 1, d+1) {
    cin>>str;
    
    bool flag = false;

    rep(j, 0, n) 
      if(str[j] == '0') {
	flag = true;
	break;
      }
    
    if(flag == true)
      a[i] = 1;
    else 
      a[i] = 0;
  }
   
  int count = 0;
  int m = 0;
  
  if(a[1] == 1)
    count = 1;
  else 
    count = 0;

  rep(i, 2, d+1) {
    if(a[i] == 1 && a[i-1] == 0)
      count = 1;
    else if(a[i] == 1 && a[i-1] == 1)
      count++;
    else if(a[i] == 0)
      m = max(m, count);
  }
  
  m = max(m, count);
  
  cout<<m<<endl;

  return 0;
}

