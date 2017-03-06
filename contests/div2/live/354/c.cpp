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

int ret_max(int a[], int k, int n) {

  int m = INT_MIN;
  int i;
  int end = 0;
  
  rep(i, 0, n) {

    if(i == 0) {
      while(end < n-1 && a[end] <= k)
	end++;
      
      while(a[end] > k && end >= 0)
	end--; 
    }

    else {
      while( end < n-1 && a[end] - a[i-1] <= k )
	end++;

      if(end > n)
	end = n-1;
      
      while(a[end] - a[i-1] > k && end >= 0)
	end--; 
    }
    //cout<<i<<" "<<end<<endl;
    m = max(m, end-i+1);
  }
  
  return m;
}

int main() {

  int n, k, a[100010], i;
  
  char str[100010];

  cin>>n>>k;

  cin>>str;

  //case 1

  rep(i, 0, n) {
    if(str[i] == 'a')
      a[i] = 0;
    else
      a[i] = 1;
  }

  rep(i, 1, n)
    a[i] += a[i-1];

  int p = ret_max(a, k , n);
  
  //cout<<p<<endl;

  //case2

  rep(i, 0, n) {
    if(str[i] == 'a')
      a[i] = 1;
    else
      a[i] = 0;
  }

  rep(i, 1, n)
    a[i] += a[i-1];

  p = max(p, ret_max(a, k ,n));

  cout<<p<<endl;
  
  return 0;
}

