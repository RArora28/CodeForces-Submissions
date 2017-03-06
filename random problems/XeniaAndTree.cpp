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
#define F first
#define S second
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

vector< VI > adj;
bool taken[MAXSIZE], cen[MAXSIZE];
int ans[MAXSIZE], T[MAXSIZE], L[MAXSIZE], P[MAXSIZE][30], parent[MAXSIZE], sub[MAXSIZE];

void dfs0(int v) { 
  taken[v] = true;
  for(auto it : adj[v]) 
    if(!taken[it])
      T[it] = v, L[it] = L[v]+1, dfs0(it);
  return;
}
void process(int N) { 
  int i, j;
  SET(P, -1);
  rep(i, 1, N+1)
    P[i][0] = T[i];
  
  for(j = 1; (1 << j) < N; j++) 
    rep(i, 1, N+1)
      if(P[i][j-1] != -1)
	P[i][j] = P[P[i][j-1]][j-1];
  return;
}
int LCA(int p, int q) { 
  int i;
  if(L[p] < L[q])
    swap(p, q);
  int log;
  for(log = 1; (1 << log) <= L[p]; log++);
  log--;
  rev(i, log, -1) {
    if(L[p] - (1 << i) >= L[q])
      p = P[p][i];
  }
  if(p == q)
   return p;
  rev(i, log, -1) 
    if(P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q = P[q][i];
  return T[p];
}


//-------------Centroid Decomposition----------------//
//function to calculate the sizes of sub-trees
void dfs1(int v, int p) { 
  sub[v] = 1;
  for(auto it : adj[v])
    if( it != p && (!cen[it]))
      dfs1(it, v), sub[v] += sub[it];
  return;
}
//function that returns the centroid of a given sub-tree
int dfs2(int v, int p, int size) { 
  for(auto it : adj[v]) 
    if( (!cen[it]) && (it != p) && (2*sub[it] > size) ) 
      return dfs2(it, v, size);
  return v;
}
//decomposition function
void decompose(int v, int p) {
  dfs1(v, v);
  int centroid = dfs2(v, v, sub[v]);
  if(p == -1) p = centroid;
  parent[centroid] = p;
  cen[centroid] = true;
  for(auto &it : adj[centroid]) { 
    if(!cen[it]) 
      decompose(it, centroid);
  }
  adj[centroid].clear();
  return;
} 

//querying
int dist(int x, int y) { 
  return abs (L[x] + L[y] - 2*L[LCA(x, y)] );
}
//log^2(n)
void update(int x, int u) { 
  //trace(x, u, dist(x, u));
  ans[x] = min(ans[x], dist(x, u));
  //trace(ans[x]);
  if( x != parent[x])
    update(parent[x], u);
  return;
}
//logn
int query(int x, int u) {
  //trace(x, u, dist(x, u));
  if(x == parent[x])
    return dist(x, u) + ans[x];
  return min(dist(x, u) + ans[x], query(parent[x], u));
}


int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  int n, m;
  cin>>n>>m;
  adj.resize(n+1);
  int i;
  int u, v;
  rep(i, 1, n) {
    cin>>u>>v;
    adj[u].PB(v);
    adj[v].PB(u);
    ans[i] = INF/10;
  }
  ans[n] = INF/10;
  T[1] = -1;
  L[1] = 0;
  dfs0(1);
  process(n);
  decompose(1, -1);

  rep(i, 1, n+1) { 
    trace(i, parent[i]);
  }

  update(1, 1);
  int t;
  while(m--) { 
    cin>>t>>v;
    if(t == 1)
      update(v, v);
    else 
      cout<<query(v, v)<<endl;
  }

  return 0;
}
