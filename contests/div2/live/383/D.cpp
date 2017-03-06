/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 100005
#define mod 1000000007
#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)
#define INF INT_MAX
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define SET(a,b) memset(a, b, sizeof(a))

//debugging statements
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

int n, m, w, j;
int i;
int w1[2010], b[2010], W[2010], B[2010], D[2000][2000];
bool vis[1010];
vector<VI> adj, group;
VI G;

void dfs(int x, int v) {
  vis[v] = true;
  B[x] += b[v];
  W[x] += w1[v];
  group[x].PB(v);
  
  for(auto it : adj[v])
    if(!vis[it])
      dfs(x, it);
  return;
}

int dp( int ind, int We )
{
  if(ind == (int)G.size())
    {
      if(We <= w)
	return 0;
      return INT_MIN;
    }
  else if(We > w)
    return INT_MIN;
  else if(D[ind][We] != -1)
    return D[ind][We];
  else {
    int g = G[ind];
    D[ind][We] = B[g] + dp(ind+1, We + W[g]);
    for(auto it : group[g])
      D[ind][We] = max(D[ind][We], b[it] + dp(ind+1, We + w1[it]));
    D[ind][We] = max(D[ind][We], dp(ind+1, We));
    return D[ind][We];
  }
}

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
 
  cin>>n>>m>>w;
  
  adj.resize(n+1);
  group.resize(n+1);

  rep(i, 0, 2000)
    rep(j, 0, 2000)
    D[i][j] = -1;
  
  rep(i, 1, n+1)
    cin>>w1[i];
  
  rep(i, 1, n+1)
    cin>>b[i];
  
  int x, y;
  
  rep(i, 1, m+1) {
    cin>>x>>y;
    adj[x].PB(y);
    adj[y].PB(x);
  }
  
  rep(i, 1, n+1) {
    if(!vis[i]) {
      G.PB(i);
      dfs(i, i);
    }
  }
  
  cout<<dp(0, 0)<<endl;
   
  return 0;
}
