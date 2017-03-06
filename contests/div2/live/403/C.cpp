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

int ans = -1;
int color[300010];
vector<VI> g;
set<int> s;

void dfs1(int v, int p) {
	ans = max(ans, (int)g[v].size() + 1);
	for(auto u : g[v])  {
		if(u != p) {
			dfs1(u, v);
		}
	}
	return;
}

void dfs2(int v, int p) {
	int t = 1;
  vector<int> V;
  for(int i = 0; i < (int)g[v].size(); i++) {
    if(p != -1 && t == color[p]) {
      t++;
      i--;
    }
    else if(t == color[v]) {
      t++;
      i--;
    }
    else {
      V.PB(t);
      t++;
    }
  }

  int j = 0;
  for(auto u : g[v]) {
		if( u != p) {
      color[u] = V[j++];
      dfs2(u, v);
		}
	}
  
	return;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n;
  cin >> n; 
  g.resize(n+10);
  int u, v;

  for(int i = 1; i < n; i++) {
  	cin >> u >> v;
  	g[u].PB(v);
  	g[v].PB(u);
  }  

  dfs1(1, -1);
  color[1] = 1;
  dfs2(1, -1);
  cout << ans << '\n';
  for(int i = 1; i <= n; i++) 
  	cout << color[i] << ' ';

  return 0;
}
