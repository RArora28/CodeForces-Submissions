#include<bits/stdc++.h>
#include<limits.h>
#include<cstdlib>
using namespace std;

#define mod 5
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

  string str1, str2;
  int x;
  
  cin>>str1;

  int len = str1.size();
  
  if(len >= 2) {
    str2 = str1.substr(len-2, 2);
    x = stoi(str2);
  }
  else {
    x = stoi(str1);
  }
     
  //cout<<x<<endl;
  
  if(x % 4 == 0)
    cout<<"4"<<endl;
  else
    cout<<"0"<<endl;
  
  return 0;
}

