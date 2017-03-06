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

  int i, j, k, ans;
  char str[110];

  cin>>str;
  int len = strlen(str);

  rep(i, 0, len) {
    rep(j, i+1, len) {
      rep(k, j+1, len) {
	ans = (str[i]-'0')*100 + (str[j]-'0')*10 + (str[k]-'0');
	if(ans % 8 == 0) {
	  cout<<"YES"<<endl;
	  cout<<ans<<endl;
	  return 0;
	}
      }
    }
  }

  rep(j, 0, len) {
    rep(k, j+1, len) {
      ans = (str[j]-'0')*10 + (str[k]-'0');
      if(ans % 8 == 0) {
	cout<<"YES"<<endl;
	cout<<ans<<endl;
	return 0;
      }
    }
  }
  
  rep(i, 0, len) {
    if(str[i] == '0' || str[i] == '8') {
      cout<<"YES"<<endl<<str[i]<<endl;
      return 0;
    }
  }
  
  cout<<"NO"<<endl;
  
  return 0;
}

