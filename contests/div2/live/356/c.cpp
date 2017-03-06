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

int arr[102];

int main() {

  int i, n, a;
  char str[10];
  
  int primes[100] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  int fac = 0, ind = 0, counter = 1, temp = primes[ind];

  while(counter <= 20) {
    pi(temp);
    fflush(stdout);
    cin>>str;

    if(str[0] == 'y') {
      if(fac == 1) {
	printf("composite\n");
	fflush(stdout);
	return 0;
      }
      else {
	fac++;
	temp *= primes[ind];
      }
    }
    
    else {
      if(fac == 0) 
	temp = primes[++ind];
  
      else {
	temp /= primes[ind];
	temp *= primes[++ind];
      }
    }

    if(temp > 100 || temp*temp > 100 && fac == 0) {
      printf("prime\n");
      //fflush(stdout);
      return 0;
    }
  }
  
  return 0;
}

