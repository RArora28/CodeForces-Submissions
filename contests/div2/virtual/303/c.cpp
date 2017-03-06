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

int x[100010], h[100010], marked[100010];

int main() { 
  
  int i,  n;

  marked[1] = -1;

  cin>>n;
  
  int count = 1;

  rep(i, 1, n+1) 
    cin>>x[i]>>h[i];

  if(h[2] < x[2]-x[1]) {
    marked[2] = -1;
    count++;
  }

  rep(i, 2, n-1) {
    if(marked[i] == 0) {
      if(h[i] + h[i+1] < x[i+1]-x[i]) {
	marked[i] = 1;
	marked[i+1] = -1;
	count+=2;
      }
      else if(h[i] < x[i+1]-x[i]) {
	marked[i] = 1;
	count++;
      }
      else if(h[i+1] < x[i+1]-x[i]) {
	marked[i+1] = -1;
	count++;
      }
    }

    else {
      if(h[i+1] < x[i+1]-x[i]) {
	marked[i+1] = -1;
	count++;
      }
    }
  }

  if(n != 1) {
    
    if(marked[n-1] == 0) {
      if(h[n-1] < x[n]-x[n-1]) {
	marked[n-1] = 1;
	count++;
      }
    }
    count++;
  }

  cout<<count<<endl;

  return 0;
}

