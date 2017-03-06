/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int ,long long int> II;
typedef vector<long long int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 100005
#define mod 1000000007
#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)
#define INF LLONG_MAX
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))
#define end "\n"

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

void shortest_path(LL dis[], LL source) {
  
  priority_queue <II, VII, greater<II > > p;
  int d, u;
  SET(d, INF);
  dis[source] = 0;
  p.push(ii(0, source));
  
  while(!p.empty()) {
    
    II temp = p.top();
    p.pop();
    d = temp.fi;
    u = temp.se;
    
    if(d > dis[u]) continue;
    
    for(VII::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
      if((LL)(d + (*it).fi) < dis[(*it).se]) {
	dis[(*it).se] = (LL)(d + (*it).fi);
	p.push(ii(dis[(*it).se], (*it).se));
      }
    }
  }
  
  return;
}


void dfs(int v, int k, int j) { 
  
  taken[v] = true;

  LL i;
  LL u;

  rep(i, 0, adj[v].size()) {
    u = adj[v][i].F;

    if(!taken[u]) { 
      if(X[u] && X[v]) { 
      }
    }
      
int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n, m, L, s, t;

  cin>>n>>m>>L>>s>>t;

  LL i;

  rep(i, 1, m+1) {
    cin>>U[i]>>V[i]>>W[i];
    adj[U[i]].PB(MP(W[i], V[i]));
    adj[V[i]].PB(MP(W[i], U[i]));
  }
  
  shortest_path(d1, s);
  LL ans = d1[t];
  shortest_path(d2, t);
  
  if(ans < L || ans == INF) { 
    cout<<"NO"<<endl;
    return 0;
  }

  rep(i, 1, m+1) { 
    if((d1[U[i]] + d2[V[i]] == ans) || (d1[U[i]] + d2[V[i]] == ans)) {
      X[U[i]] = true;
      X[V[i]] = true;
      
    }
  }
  
  //assign lengths: 
  bool first = false;
  //call dfs;

  //final check

  LL temp = shortest(d3, s);
  LL Ans = d3[t];

  if(Ans != L)
    cout<<"NO"<<endl;
  else { 
    //print the edge list;

  }
  
  return 0;
}
