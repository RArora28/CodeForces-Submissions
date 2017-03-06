/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 300005
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

int centroid[MAXSIZE], A[MAXSIZE], P[MAXSIZE], sub[MAXSIZE];
bool taken[MAXSIZE];
vector<VI> adj;

int assign_centroid(int x, int v) { 
  
  //cout<<endl;
  //cout<<"ye hai v:"<<v<<endl;
  //trace(sub[v]);
  while(2*sub[x] < sub[v] && P[x] != x) {
    //trace(x);
    x = P[x];
  }
  
  //cout<<"ended"<<endl;

  return x;
}

int dfs(int v) { 
  
  int child = 1;
  bool entered = false;
  int Max = -1, kid;
  taken[v] = true;

  for(auto it : adj[v])
    if(!taken[it]) {
      kid = dfs(it);
      child += kid;

      if(kid > Max) {
	Max = kid;
	A[v] = it;
      }
      entered = true;
    }
  
  sub[v] = child;

  if(!entered) { 
    centroid[v] = v;
    A[v] = v;
  }
  else 
    centroid[v] = assign_centroid(centroid[A[v]], v);
  
  return sub[v];
}

int main() {

  int n, q;
  int i;

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  cin>>n>>q;

  adj.resize(n+1);

  rep(i, 2, n+1) { 
    cin>>P[i]; 
    adj[i].PB(P[i]);
    adj[P[i]].PB(i);
  }

  P[1] = 1;
  dfs(1);
  
  int x;

  while(q--) { 
    cin>>x;
    cout<<centroid[x]<<endl;
  }

  return 0;
}
