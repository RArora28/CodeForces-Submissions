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

  int i, count1 = 0, count2 = 0;
  char str[100010];

  cin>>str;

  int len = strlen(str);
  
  vi v1, v2;
  
  rep(i, 0, len) {

    if(i+1 < len && (str[i] == 'A' && str[i+1] == 'B')) {
      v1.pb(i);
      count1++;
    }
    else if(i+1 < len && (str[i] == 'B' && str[i+1] == 'A')) {
      v2.pb(i);
      count2++;
    }
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  int ans = 0;

  if(count1 >= 1 && count2 >= 1)
    ans = max(v1[v1.size()-1] - v2[0], v2[v2.size()-1] - v1[0]);

  if(ans >= 2)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  
  return 0;
}

