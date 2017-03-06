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

const int N = 1e5+5;

bool vis[N], cen[N];
int sub[N], L[N], parent[N];
vector<VI> adj, g;

void dfs1(int v, int p)
{
  sub[v] = 1;
  for(auto it : adj[v])
    if( (it != p) && (!cen[it]) )
      dfs1(it, v), sub[v] += sub[it];
  return;
}
int dfs2(int v, int p, int size)
{
  for(auto it : adj[v])
    if( (!cen[it]) && (it != p) && (2*sub[it] > size) )
      return dfs2(it, v, size);
  return v;
}
void decompose(int v, int p)
{
  dfs1(v, v);
  int centroid = dfs2(v, v, sub[v]);
  if(p == -1) p = centroid;
  parent[centroid] = p;
  cen[centroid] = true; 
  for(auto it : adj[centroid])
    if( !cen[it])
      decompose(it, centroid);
  return;
}

bool imp = false;

void dfs(int v) {
  vis[v] = true;
  if(L[v] > 25)
    imp = true;
  for(auto it : g[v])
    if ( !vis[it])
      L[it] = L[v] + 1, dfs(it);
  return;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n;
  cin>>n;

  int i;

  int a, b;

  adj.resize(n+1);
  g.resize(n+1);
  
  rep(i, 1, n)
    {
      cin>>a>>b;
      adj[a].PB(b);
      adj[b].PB(a);
    }
  decompose(1, -1);
  int c = 0;
  rep(i, 1, n+1)
    {
      if(parent[i] != i)
	{
	  g[i].PB(parent[i]);
	  g[parent[i]].PB(i);
	}
      else
	c= i;
    }
  
  L[c] = 0;
  dfs(c);
  if(!imp)
    rep(i, 1, n+1)
      cout<<(char)('A'+L[i])<<" ";
  else
    cout<<"Impossible";
  cout<<endl;
  return 0;
}
