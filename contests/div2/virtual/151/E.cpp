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

bool big[N], root[N];
int t[N], sub[N], cnt[N], bigchild[N], ans[N], L[N], n;
string s[N];
vector< map<string, int> > m;
vector<VI> g;
vector<VII> Q;
void dfs0(int v, int p)
{
  sub[v] = 1;
  bigchild[v] = -1;
  int Max = -1;
  for(auto u : g[v])
    {
      if( u != p)
	{
	  L[u] = L[v]+1;
	  dfs0(u, v);
	  sub[v] += sub[u];
	  if(sub[u] > Max)
	    {
	      Max = sub[u];
	      bigchild[v] = u;
	    }
	}
    }
  return;
}
void add(int v, int p)
{
  m[L[v]][s[v]]++;
  if(m[L[v]][s[v]] == 1)
    cnt[L[v]]++;
  for(auto u : g[v])
    if( u != p && (!big[u]))
      add(u, v);
  return;
}
void rem(int v, int p)
{
  m[L[v]][s[v]]--;
  if(m[L[v]][s[v]] == 0)
    cnt[L[v]]--;
  for(auto u : g[v])
    if( (u != p) && (!big[u]) )
      rem(u, v);
  return;
  
}
void dfs2(int v, int p, int keep)
{
  int i;
  for(auto u : g[v])
    if(u != p && u != bigchild[v]) 
      dfs2(u, v, false);
  if(bigchild[v] != -1)
    {
      dfs2(bigchild[v], v, true);
      big[bigchild[v]] = true;
    }
  add(v, p);
  //trace(v, Q[v].size(), bigchild[v]);
  // rep(i, 0, (int)m.size())
  //   {
  //     cout << i << "->" << endl;
  //     for(auto x : m[i])
  // 	trace(x.F, x.S);
  //   }
  for(auto x : Q[v])
    {
      if(x.F + L[v] <= n)
	{
	  t[x.S] = cnt[x.F+L[v]];
	  //trace(x.F + L[v]);
	}
      else
	t[x.S] = 0;
    } 
  big[bigchild[v]] = false;
  if(keep == false)
      rem(v, p);
  return;
}

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  int i, x, q;
  cin >> n;
  g.resize(n+2);
  Q.resize(n+2);
  m.resize(n+2);
  rep(i, 1, n+1)
    {
      cin >> s[i] >> x;
      if(x != 0)
	{
	  g[x].PB(i);
	  g[i].PB(x);
	}
      else
	root[i] = true;
    }
  int z;
  cin >> z;
  rep(i, 1, z+1)
    {
      int a, b;
      cin >> a >> b;
      Q[a].PB({b, i});
    }

  
  rep(i, 1, n+1)
    {
      if(root[i])
	{
	  dfs0(i, i);
	  dfs2(i, i, false);
	}
    }
  rep(i, 1, z+1)
    cout << t[i] << endl;
  return 0;
}
