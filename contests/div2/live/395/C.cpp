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
bool ret = false;
int c[N];
int root = 1;

int dfs0(int v, int p) {
	for(auto u : g[v]) {
		if( u != p) {
			int x = dfs0(u, v);
			if(x != c[v] && !ret) {
				ret = true;
				root = v;
			}
		}
	}
	return c[v];
}

bool ok = true;

void dfs1(int v, int p, int val) {
	if(c[v] != val) {
		ok = false;
	}
	for(auto u : g[v]) {
		if( u != p) {
			dfs1(u, v, val);
		}
	}
	return;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int n, a, b; 
  cin >> n; g.resize(n+10);
  for(int i = 1; i < n; i++) {
  	cin >> a >> b;
  	g[a].PB(b);
  	g[b].PB(a);
  }
  for(int i = 1; i <= n; i++) {
  	cin >> c[i];
  }
  dfs0(1, -1);
  for(auto u : g[root]) {
  	dfs1(u, root, c[u]);
  }

  if(ok) {
  	cout << "YES" << '\n' << root << '\n';
  }
  else {
  	cout << "NO" << endl;
  }
  return 0;
}
