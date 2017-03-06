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

int a[171];

int main() { 

  int i, j, N;

  cin>>N;

  int arr1[N+1][N+1];
  
  rep(i, 1, N+1) {
    rep(j, 1, N+1) {
      
      cin>>arr1[i][j];
      
      int temp = arr1[i][j];

      
      if(temp == 1) 
	a[i] = -1;

      else if(temp == 2) 
	a[j] = -1;
      
      else if(temp == 3)
	a[i] = a[j] = -1;
    }
  }

  int count = 0;

  rep(i, 1, N+1) {
    if(a[i] == 0)
      count++;
    
  }

  cout<<count<<endl;
  
  rep(i, 1, N+1) {
    if(a[i] == 0)
      cout<<i<<" ";
  }
  
  return 0;
}

