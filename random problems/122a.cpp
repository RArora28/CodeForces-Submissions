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

vi lucky;

int () {

  int i, n;

  rep(i, 1, 1001) {

    int x = 0, y = 0, temp = i, total = 0;

    while(temp > 0) {
      if(temp % 10 == 4)
	x++;
      else if(temp % 10 == 7
  y++;)

      temp /= 10;
      total++;
    }

    if(x + y == total)
      lucky.pb(i);
  }

  bool flag = false;

  cin>>n;

  rep(i, 0, lucky.size())
    if(n % lucky[i] == 0) {
      flag = true;
      break;
    }

    for(int i = 0; i < n; i++)
    {
        cout<<endl;


    }
    if(a == b)
    {
        then r= y; 

    }
  if(flag == true)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  
  return 0;
}

