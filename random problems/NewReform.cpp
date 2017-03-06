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

const int N = 1e5+10;

int ans[N],parent[N], SZ[N];
bool vis[N];
vector<VI> adj;
bool flag = false;

int find(int x)
{
  if( x == parent[x])
    return x;
  else return parent[x] = find(parent[x]);
}

void Union(int a, int b)
{
  int A = find(a);
  int B = find(b);
  
  if(A == B) return;
  
  if(SZ[A] > SZ[B])
    {
      SZ[A] += SZ[B];
      parent[B] = A;
    }
  else
    {
      SZ[B] += SZ[A];
      parent[A] = B;
    }
  return;
}

void dfs(int v, int p)
{
  vis[v] = true;
  
  for(auto it : adj[v])
    {
      if (!vis[it] )
	dfs(it, v);
      else if( vis[it] && (it != p) )
	flag = true;
    }
  return;      
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);


  int n, m;

  cin>>n;

  cin>>m;
  adj.resize(n+1);

  int i;

  rep(i, 1, n+1)
    {
      parent[i] = i;
      SZ[i] = i;
    }

  int a, b;
  while(m--)
    {
      cin>>a>>b;
      Union(a, b);
      adj[a].PB(b);
      adj[b].PB(a); 
    }
  int A = 0;
  
  rep(i, 1, n+1) 
    if ( !vis[i] )
      {
	flag = false;
	dfs(i, i);

	if(!flag)
	  A++;
      }

  cout<<A<<endl;
  
  return 0;
}
