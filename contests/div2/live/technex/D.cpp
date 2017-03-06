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

vector<VI> g[2];
bool currOn[N], initialON[N], vis[2][N];
int r[N];

void dfs(int v, int opt) {
	vis[opt][v] = true;
	if(opt == 0) {
		if(initialON[v] == false) {
			if(currOn[v]) {
				return;
			}
			else {
				for(auto u : g[opt][v]) {
					if(!vis[1-opt][u]) {
						currOn[u] = true;
						dfs(u, 1-opt);
						return;
					}
				}
			}
		}
	}
	else {
		for(auto u : g[opt][v]) {
			if(!vis[1-opt][u]) {
				currOn[u] = !currOn[u];
				dfs(u, 1-opt);
			}
		}
	}
	return;
}
int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int n, m;
  cin >> n >> m;
  g[0].resize(n+2);
  g[1].resize(m+2);
  int x, y;
  for(int i = 1; i <= n; i++) {
  	cin >> r[i];
  }
  int start;

  for(int i = 1; i <= m; i++) {
  	cin >> x;
  	while(x--) {
  		cin >> y;
  		g[0][x].PB(y);
  		g[1][y].PB(x);
  	}
  } 

  bool ok = true;
  for(int i = 1; i <= n; i++) {
  	if(r[i] == 0) {
  		ok = false;
  		start = i;
  		break;
  	}
  }

  if(ok) {
  	cout << "YES";
	return 0;
	}  
  for(int i = 1; i <= n; i++) {
  	if(r[i]) {
  		initialON[i] = true;
  		currOn[i] = true;
  	}
  	else initialON[i] = false;
  }

  SET(currOn, false);
  SET(vis, false);
  dfs(start, 0);
 	
  ok = true;
  for(int i = 1; i <= n; i++) {
  	if(!currOn[i]) {
  		ok = false;
  		break;
  	}

  }

  for(int i = 1; i <= n; i++) {
  	if(r[i]) {
  		initialON[i] = true;
  		currOn[i] = true;
  	}
  	else initialON[i] = false;
  }

  SET(currOn, false);
  SET(vis, false);
  dfs(start, 0);
	ok = true;
  for(int i = 1; i <= n; i++) {
  	if(!currOn[i]) {
  		ok = false;
  		break;
  	}

  }  
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
