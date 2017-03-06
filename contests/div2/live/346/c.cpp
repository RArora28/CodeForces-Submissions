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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

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

int a[10000000];

set<int> s;
vi v;

int main() {

  int n, m, x;

  cin>>n>>m;

  int j;
  
  rep(j, 1, n+1) {
    si(x);
    s.insert(x);
  }

  int i = 1, cot = 0, sum = 0;
  
  while(1) {
    
    if(!s.count(i))
      if(sum + i <= m){
      sum += i;
      cot++;
      v.pb(i);
    }

    else if(sum + i > m)
      break;
     
    i++;
  }

  cout<<cot<<endl;

  rep(i, 0, v.size()) {
    cout<<v[i]<<" ";
  }

  cout<<endl;

  return 0;
}
