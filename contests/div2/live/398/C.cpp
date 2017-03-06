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

const int N = 1e6+10;
const int mod = 1e9+7;

int root;
vector<VI> g;
VI ans;
int sub[N], t[N];

void dfs0(int v, int p) {
	sub[v] = t[v];
	for(auto u : g[v]) {
		if( u != p) {
			dfs0(u, v);
			sub[v] += sub[u];
		}
	}
	return;
}

int dfs1(int v, int p) {
	int ret = -1, temp;
	if( (v!=root) && 3*sub[v] == sub[root]) {
		ret = v;
	}
	VI ans;
	for(auto u : g[v]) {
		if(u != p) {
			temp = dfs1(u, v);
			if(temp != -1) {
				if(ret == -1) ret = temp;
				if( sub[v] == 2*sub[temp] && (sub[root]-sub[v] == sub[temp]) && (v != root) ) {
					cout << min(v,temp) << ' ' << max(v,temp) << '\n';
					exit(0);
				}
				ans.PB(temp);
				if(ans.size() >= 2) {
					cout << min(ans[0], ans[1]) << ' ' << max(ans[0],ans[1]) << '\n';
					exit(0);
				}
			}
		}
	}
	return ret;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int n;
  cin >> n; g.resize(n+2);
  int p;
  for(int i = 1; i <= n; i++) {
  	cin >> p >> t[i];
  	if(p != 0) {
  		g[i].PB(p);
  		g[p].PB(i);
  	}
  	else {
  		root = i;
  	}
  }
  dfs0(root, -1);
  dfs1(root, -1);

  if((int)ans.size() < 2) {
  	cout << -1 << '\n';
  }
  else{
  	cout << min(ans[0], ans[1]) << ' ' << max(ans[0],ans[1]) << '\n';
  }
  return 0;
}