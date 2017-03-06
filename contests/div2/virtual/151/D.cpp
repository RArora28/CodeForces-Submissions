/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

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
const int mod = 1e9+7;

vector<VI> g;
int x[N], t[N], c[N];
bool vis[N];
vector<set<int> > s;

void dfs(int v)
{
  c[x[v]]++;
  vis[v] = true;
  for(auto u : g[v])
    {
      if(x[u] != x[v])
	{
	  if(s[x[v]].find(x[u]) == s[x[v]].end())
	    {
	      t[x[v]]++;
	      s[x[v]].insert(x[u]);
	    }
	}
      if(!vis[u])
	dfs(u);
    }
  return;
}

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;
  g.resize(n+1);
  s.resize(1e5+1);
  
  int i;

  rep(i, 1, n+1)
    cin >> x[i];
  
  rep(i, 0, m)
    {
      int a, b;
      cin >> a >> b;
      g[a].PB(b);
      g[b].PB(a);
    }

  //trace("hello");

  rep(i, 1, n+1)
    if(!vis[i])
      dfs(i);
  
  int ans = 1;
  int Max = -1;
  
  rep(i, 1, 1e5+1)
    {
      //trace(i, t[i], c[i]);
      if(t[i] > Max && c[i] > 0)
	{
	  Max = t[i];
	  ans = i;
	}
    }

  cout << ans << endl;
  return 0;
}
