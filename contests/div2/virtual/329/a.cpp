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

int dp[30][30], c1[37], dp1[30];

int main() { 

  int i, j, n;
  char str[1010];
  
  cin>>n;

  while(n--) { 

    cin>>str;

    int len = strlen(str);
    
    memset(c1, 0, sizeof(c1));
    
    rep(i, 0, len) 
      c1[str[i]-'a'+1]++;
    
    int count = 0; 
    int A =  0, B = 0;
    
    rep(i, 1, 27) {
      if(c1[i] > 0) {
	count++;	
	if(A == 0)
	  A = i;
	else if(A != 0 && B == 0)
	  B = i;
      }
    }
    
    if(count == 2) 
      dp[A][B] += len;
    else if(count == 1)
      dp1[A] += len;
  }
  
  int m = 0;
  
  rep(i, 1, 27) 
    m = max(m, dp1[i]);
  
  rep(i, 1, 27) 
    rep(j, 1, 27)    
      if(i != j)
	m = max(m, dp[i][j] + dp1[i] + dp1[j]);
    
  cout<<m<<endl;
  
  return 0;
}

