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
  
  int n , i;

  char str1[100010], str2[100010];

  cin>>str1>>str2;

  int len = strlen(str1);
    
  int e = 0, u = 0;
  rep(i, 0, len) {
    if(str1[i] == str2[i])
      e++;
    else u++;
  } 

  if(u % 2 == 1)
    cout<<"impossible"<<endl;
  else {
    int chance = 1;
    rep(i, 0, len) {
      if(str1[i] == str2[i])
	cout<<str1[i];
      else {
	if(chance == 1) {
	  cout<<str1[i];
	  chance = 2;
	}
	else {
	  cout<<str2[i];
	  chance = 1;
	}
      }
    }
    cout<<endl;
  }

  return 0;
}

