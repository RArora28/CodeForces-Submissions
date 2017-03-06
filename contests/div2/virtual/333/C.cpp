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

vector<VI> g[3];
int dis[3][N];

void bfs(int dest) {

	queue<II> q;

	for(int i = 1; i <= dest; i++) {
		dis[1][i] = dis[2][i] = INT_MAX;
	}

	dis[1][1] = 0;
	dis[2][1] = 0;

	q.push({1, 1});
	q.push({1, 2});
	
	while(!q.empty()) {
		II X = q.front();
		q.pop();
		int u = X.F;
		int c = X.S;
		for(auto x : g[c][u]) {
			if(dis[c][x] > dis[c][u] + 1) {
				dis[c][x] = dis[c][u] + 1;
				q.push({x, c});
			}
		}
	}
	int A = max(dis[1][dest], dis[2][dest]);
	if(A == INT_MAX)
		A = -1;
	cout << A << endl;
	return ;
}
int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  int a, b;

  g[1].resize(n+2);
  g[2].resize(n+2);

  set<II> s;

  for(int i = 1; i <= m; i++ ) {
  	cin >> a >> b;
  	g[1][a].PB(b);
  	g[1][b].PB(a);
  	s.insert({a, b});
  	s.insert({b, a});
  }

  int i , j;

  rep(i, 1, n+1) {
  	rep(j, 1, n+1) {
  		if(s.find({i, j}) == s.end() && (i != j)) {
  			g[2][i].PB(j);
  		}
  	}
  }

  bfs(n);
  return 0;
}
