#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mi 1000000007

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define dout(x) printf("%d\n", x)
#define lldout(x) printf("%lld\n", x)

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define adjList vector<vector<int> >

#define ll long long int

#define pb push_back
#define mp make_pair

#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)

ll power(ll a,ll b) {

  ll ans=1;  

  while(b > 0){
      if(b & 1)
	  ans = ((ans % mi) *(a % mi)) % mi;		
      a=((a % mi)*(a % mi)) % mi;
      b >>= 1;
    }
  
  return ans;
}

ll no[10000], ind = 0, arr[10000];

float logar(ll a, ll b) {
  return (float)log(a)/(float)log(b);
}

ll sieve(ll n) {

  ll i, j, count = 0;
  
  rep(i, 2, n+1) {
    for(j = 1; i*j <= n; j++) {
      if(no[i*j] == 0) {
	no[i*j] = 1;
	
	if(logar(i*j, i) == (ll)logar(i*j, i)) {
	  arr[ind++] = i*j;
	  count++;
	}
      }
    }
  }
  
  return count;
}

int main() {

  ll n, i;

  cin>>n;

  ll temp = sieve(n);

  cout<<temp<<endl;

  rep(i, 0, ind)
    cout<<arr[i]<<" ";
  cout<<endl;
  
  return 0;
}

