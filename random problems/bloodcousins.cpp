/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 100005
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

vector<map<int, int> > level;
vector<VI> adj;
int L[MAXSIZE], P[MAXSIZE], R[MAXSIZE];
bool taken[MAXSIZE];
int ind;

int find(int x) { 
  if(P[x] == x)
    return x;
  return P[x] = find(P[x]);
}

void combine(int a, int b) { 

  int A = find(a), B = find(b);

  if(R[A] > R[B]) {
    P[B] = A;
    R[A] += R[B];
    return;
  }

  P[A] = B;
  R[B] += R[A];
  return; 
}

void dfs(int v, int i) { 
  
  taken[v] = true;

  if(level[i].find(L[v]) != level[i].end())
    level[i][L[v]]++;
  else 
    level[i][L[v]] = 1;
  
  for(auto it : adj[v])
    if(!taken[it]) { 
      L[it] = L[v] + 1; 
      dfs(it, i);
    }
  
  return;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  SET(R, 1);

  int N, i;
  map<int, int> M;

  cin>>N;
  
  adj.resize(N+1);
  level.resize(N+1);
  
  rep(i, 1, N+1) {
    cin>>P[i];
    
    if(P[i] == 0)
      P[i] = i;
    else {
      adj[i].PB(P[i]);
      adj[P[i]].PB(i);
      combine(P[i], i);
    }
  }
  
  rep(i, 1, N+1)  
    if(!taken[i]) { 
      M[find(i)] = ind;
      dfs(i, ind);
      ind++;
    }

  int m;
  int v, p;

  cin>>m;

  while(m--) { 
    cin>>v>>p;

    int parent_v = find(v);
    
    if(L[v] < p)
      cout<<"0"<<endl;
    else 
      cout<<(level[M[parent_v]][L[v]]-1)<<endl;
  }

  return 0;
}
