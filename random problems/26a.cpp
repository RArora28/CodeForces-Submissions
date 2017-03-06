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

int arr[4000];
vi primes;

void sieve(int n) {

  int i, j;
  
  rep(i, 2, n+1) {
    for(j = 2; i*j <= n; j++) {
      arr[i*j] = 1;
    }
  }

  rep(i, 2, n+1) {
    if(!arr[i]) {
      primes.pb(i);
    }
  }
}

int main() {

  int n, i, j;
  
  cin>>n;

  sieve(n);

  //rep(i, 0, primes.size())
  //cout<<primes[i]<<endl;
  
  int count1 = 0, count2 = 0;
  
  rep(i, 2, n+1) {
    
    count2 = 0;
    j = 0;
    
    while(j < primes.size() && primes[j] <= i) {
      if(i % primes[j] == 0)
	count2++;
      j++;
    }

    //cout<<i<<":"<<count2<<endl;
    if(count2 == 2) {
      //cout<<i<<endl;
      count1++;
    }
  }

  cout<<count1<<endl;
  
  return 0;
}

