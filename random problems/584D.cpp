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

int flag[10000010];
vi primes;

void sieve(int n) {

  int i, j;

  rep(i, 2, n+1) 
    for(j = 2; i*j <= n; j++) 
      flag[i*j] = 1;

  rep(i, 2, n+1)
    if(!flag[i])
      primes.pb(i);

  return ;
}

bool isPrime(int n) {

  if(n <= 1e7) {
    if(flag[n] == 1)
      return false;
    else return true;
  }
  
  int i = 0;

  while(i < primes.size() && primes[i] * primes[i] <= n) {
    if(n % primes[i] == 0)
      return false;
    i++;
  }

  return true;
}

int main() {

  int n, i;
  
  cin>>n;
  sieve(n);


  rep(i, 0, primes.size())
    cout<<primes[i]<<endl;
  // if(isPrime(n))
  //   cout<<"1"<<endl<<n<<endl;

  // else if(isPrime(n-2)) 
  //   cout<<"2"<<endl<<"2 "<<n-2<<endl;

  // else if(isPrime(n-4))
  //   cout<<"3"<<endl<<"2 2 "<<n-4<<endl;

  
  return 0;
}
