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

vector<pair<int, vi> > dp;

pair<int, vi> give_min(int sum) {

  if(sum == 0)
    return mp(1, 0);
  else if(sum < 0)
    return mp(INT_MAX,0);
  else {
    int ans = INT_MAX;
    vi v;
    pair<int, vi> temp;
    
    rev(i, v.size(), -1) {
      if(sum >= v[i]) {
	temp = give_min(sum - v[i]);
	
	if(1 + temp.fi < ans) {
	  ans = 1 + temp.fi;
	}
      }
    }
  }
}

int main() {
  
  int n;

  cin>>n;

  dp.resize(n+1);
  
  vi v;
  
  rep(i, 0, n+1) {
    
    int temp = n;
    int count1 = 0, count2 = 0, total;
    
    while(temp > 0) {
      total++;
      if(temp % 10 == 0)
	count1++;
      else if(temp % 10 == 1)
	count2++;
      else
	break;
      
      temp /= 10;
    }
    
    if(count1 + count2 == total)
      v.pb(i);
  }
  
  
  return 0;
}

