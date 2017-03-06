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

int a[100010], flag[100010];

void dfs(int v) {

  flag[v] = 1;

  if(flag[v+a[v]] != 1)
    dfs(v+a[v]);
  return ;
}

int main() {

  int i, n, t;

  cin>>n>>t;

  rep(i, 1, n)
    cin>>a[i];

  dfs(1);

  if(flag[t] == 1)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  
  return 0;
}

