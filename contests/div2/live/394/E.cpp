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

LL X[100], Y[100];
vector<vector<LL > > g;
bool vis[100];
LL deg[100];

void dfs(LL v, LL currx, LL curry, LL pdir, LL diff) {
	vis[v] = true;
	LL cdir = 0, P;
	//trace(v, pdir, diff,currx, curry);
	for(auto u : g[v]) {
		if(!vis[u]) {
			if(cdir == pdir) {
				cdir++;
			}
			//trace(v, u, cdir);
			X[u] = currx;
			Y[u] = curry;
			if(cdir == 0) {
				X[u] -= diff/2;
				P = 1;
			}
			else if(cdir == 1) {
				X[u] += diff/2;
				P = 0;
			}
			else if(cdir == 2) {
				Y[u] += diff/2;
				P = 3;
			}
			else if(cdir == 3){
				Y[u] -= diff/2;
				P = 2;
			}
			dfs(u, X[u], Y[u], P, diff/2);
			cdir++;
		}
	}
	return ;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n;
  cin >> n;
  g.resize(n+1);
  for(int i = 1; i < n; i++) {
  	LL a, b; cin >> a >> b;
  	g[a].PB(b); g[b].PB(a);
  	deg[a]++; deg[b]++;
  }

  for(int i = 1; i <= n; i++) {
  	if(deg[i] > 4) {
  		cout << "NO" << '\n';
  		return 0;
  	}
  }

  cout << "YES" << '\n';
  X[1] = 0, Y[1] = 0;
  dfs(1, 0, 0, -1,1e18);
  for(int i = 1 ; i <= n; i++) {
  	cout << X[i] << ' ' << Y[i] << endl;
  }
  return 0;
}
