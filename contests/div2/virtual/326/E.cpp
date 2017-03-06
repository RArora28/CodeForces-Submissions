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

struct node { 
  int l, r, lc, i, k;
  bool flag;
};

int sq, ans = 0, tim = 1, hi[MAXSIZE], c[MAXSIZE], arr[2*MAXSIZE], in[MAXSIZE], out[MAXSIZE], L[MAXSIZE], par[MAXSIZE], P[MAXSIZE][50], cnt[MAXSIZE], vis[MAXSIZE];
vector<VI> query, Ne;
bool taken[MAXSIZE];
vector<VI > adj;
vector<node> Q;
set<int> s;

inline bool cmp(node A, node B) { 
  if(A.l/sq != B.l/sq)
    return A.l/sq < B.l/sq;
  return A.r < B.r;  
}
 
inline int read_int() {
  char c;
  while (c = getchar(), c < '0' || c > '9');
  int t = c - '0';
  while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
  return t;
}
 
void dfs(int v) { 
  taken[v] = true;
  in[v] = tim++;
  arr[in[v]] = v;
  for(auto it : adj[v])
    if(!taken[it]) {
      par[it] = v;
      L[it] = L[v] + 1;
      dfs(it);
    }
  out[v] = tim++;
  arr[out[v]] = v;
  return;
}

inline void LCApre(int n) { 
  int i, j;
  rep(i, 1, n+1)
    P[i][0] = par[i];
  rep(i, 1, n+1)
    for(j = 1; 1 << j < n; j++)
      if(P[i][j-1] != -1)
	P[i][j] = P[P[i][j-1]][j-1];
  return; 
}

inline int LCA(int a, int b) { 
  int i, log;
  if(L[a] < L[b])
    swap(a, b);
  for(log = 1; 1 << log <= L[a]; log++);
  log--;
  rev(i, log, -1)
    if(L[a] - (1 << i) >= L[b])
      a = P[a][i];
  if(a == b)
    return a;
  rev(i, log, -1)
    if(P[a][i] != -1 && P[a][i] != P[b][i])
      a = P[a][i], b = P[b][i];
  return par[a];
}

inline void add1(int x) { 
  vis[x] ^= 1;
  if(vis[x] == 0)  
    ans -= hi[x];
  else 
    ans += hi[x];
  return; 
}

inline void remove1(int x) {
  vis[x] ^= 1;
  if(vis[x] == 0)  
    ans -= hi[x];
  else 
    ans += hi[x];
  return; 
}

inline void add2(int x) { 
  vis[x] ^= 1;
  if(vis[x] == 1)
    for(auto it : Ne[x])  
      s.insert(it);
  else 
    for(auto it : Ne[x])
      s.erase(it);
  return;
}

inline void remove2(int x) { 
  vis[x] ^= 1;
  if(vis[x] == 1)
    for(auto it : Ne[x])  
      s.insert(it);
  else 
    for(auto it : Ne[x])
      s.erase(it);
  return;
}
 
int main() {
  
  int n, m, i, j, u, v, q, a;
  
  cin>>n>>m>>q;

  adj.resize(n+1);
  Ne.resize(n+1);
  query.resize(q+10);

  rep(i, 1, n) {
    cin>>u>>v;
    adj[u].PB(v);
    adj[v].PB(u);
  }
  
  rep(i, 1, m+1) { 
    cin>>c[i];
    hi[c[i]]++;
    Ne[c[i]].PB(i);
  }
  
  
  rep(i, 1, n+1)
    rep(j, 0, 30)
    P[i][j] = -1;

  L[1] = 0, par[1] = -1;
  dfs(1);
  LCApre(n);
  sq = sqrt(2*n);
  int L;

  rep(i, 1, q+1) { 
    node T;
    
    cin>>u>>v>>a;
    if(in[u] > in[v])
      swap(u, v);
    L = LCA(u, v);
    //trace(u, v, L);
    T.i = i, T.lc = L, T.k = a;
    if(L == u) { 
     T.l = in[u];
     T.r = in[v];
     T.flag = false;
    }
    else {
      T.l = out[u];
      T.r = in[v];
      T.flag = true;
    }  
    Q.PB(T);
  }

  sort(Q.begin(), Q.end(), cmp);
  
  int start = 1, end =1 ;
  int alpha;
  ans = 0;

  for(auto &X : Q) { 
    int L = X.l, R = X.r;
    bool flag = X.flag;
    while(end <= R) add1(arr[end++]);  
    while(end > (R+1) )  { remove1(arr[end-1]); end--; } 
    while(start < L) remove1(arr[start++]); 
    while(start > L ) { add1(arr[start-1]); start--; } 
    alpha = ans;
    if(flag) 
      alpha += hi[X.lc];
    X.k = min(X.k, alpha);
  }
  
  //found the min on a path
  
  rep(i, 1, n+1)
    vis[i] = 0;

  start = 1, end = 1;
  
  for(auto X : Q) { 
    int L = X.l, R = X.r;
    bool flag = X.flag;
    int I = X.i;
    
    while(end <= R) add2(arr[end++]);  
    while(end > (R+1) )  { remove2(arr[end-1]); end--; } 
    while(start < L) remove2(arr[start++]); 
    while(start > L ) { add2(arr[start-1]); start--; } 
    if(flag) 
      for(auto it : Ne[X.lc])
	s.insert(it);
    
    query[I].PB(X.k);
    
    int ind = 1;
    
    for(auto t : s) {
      if(ind == (X.k+1))
	break;
      else 
	query[I].PB(t);
      ind++;
    }
    
    if(flag) 
      for(auto it : Ne[X.lc])
	s.erase(it);
  }

  for(auto it1 : query) { 
    for(auto it2: it1)
      cout<<it2<<" ";
    cout<<endl;
  }

  return 0;
}
