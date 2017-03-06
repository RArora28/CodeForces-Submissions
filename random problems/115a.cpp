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

adjList g;

int p[10000], dis[10000];

void dfs(int v) {
  
  for(vi::iterator it = g[v].begin(); it != g[v].end(); it++) {
    if(dis[v] + 1 > dis[*it]) {
      dis[*it] = dis[v] + 1;
      dfs(*it);
    }
  }

  return ;
}

int main() {
  
  int n, i;
  cin>>n;
  
  g.resize(n+1);
  
  rep(i, 1, n+1)
    {
      cin>>p[i];
      
      if(p[i] != -1) {  
	g[p[i]].push_back(i);
	dis[i] = INT_MIN;
      }
      
      else
	dis[i] = 1;
    }

  rep(i, 1, n+1)
    if(dis[i] != INT_MIN)
      dfs(i);
  
  int maximum = dis[1];

  rep(i, 2, n+1)
    maximum = max(maximum, dis[i]);

  cout<<maximum<<endl;
  
  return 0;
}

