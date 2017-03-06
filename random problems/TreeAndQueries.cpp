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
  int  i, l, r, K;
};

int sq, K;
int ans = 0, tim = 1, kk[MAXSIZE], color[MAXSIZE], arr[MAXSIZE], in[MAXSIZE], out[MAXSIZE],  cnt[MAXSIZE],  query[MAXSIZE];
bool taken[MAXSIZE];
vector<vector<int> > adj;
vector<node>Q;

inline bool cmp(node A, node B) { 
  if(A.l/sq != B.l/sq)
    return A.l/sq < B.l/sq;
  return A.r < B.r;  
}

void dfs(int v) { 
  taken[v] = true;
  in[v] = tim++;
  arr[in[v]] = v;
  for(auto it : adj[v])
    if(!taken[it]) 
      dfs(it);
  out[v] = tim;
  out[v]--;
  return;
}

int main() {
  
  int n, m;
  int i;
  int u, v;
  
  cin>>n>>m;
  
  adj.resize(n+1);

  rep(i, 1, n+1) 
    cin>>color[i];
 
  rep(i, 1, n) {
    cin>>u>>v;
    adj[u].PB(v);
    adj[v].PB(u);
  }
  
  dfs(1);
  
  sq = sqrt(n);
  int sz = n / sq + 2;
  
  rep(i, 1, m+1) { 
    node T;
    cin>>v>>K;
    T.l = in[v];
    T.r = out[v];
    T.K = K;
    T.i = i;
    Q.PB(T);
  }

  sort(Q.begin(), Q.end(), cmp);
  
  int start = 1, end = 1;
 
  for(auto X : Q) { 
    int L = X.l, R = X.r;
    int I = X.i;
    K = X.K;

    //trace(L, R, start, end);
    while(end <= R) { 
      cnt[color[arr[end]]]++;
      kk[cnt[color[arr[end]]]]++;
      end++;
    } 
    
    while(end > (R+1)) { 
      kk[cnt[color[arr[end-1]]]]--;
      cnt[color[arr[end-1]]]--;
      end--;
    }

    while(start < L) {
      kk[cnt[color[arr[start]]]]--;
      cnt[color[arr[start]]]--;
	start++;
    }
    
    while(start > L) {
      cnt[color[arr[start-1]]]++;
      kk[cnt[color[arr[start-1]]]]++;
      start--;
    }
    
    //trace(L, R, start, end);
    query[I] = kk[K]; 
  }
  
  rep(i, 1, m+1)
    printf("%d\n", query[i]);
  
  return 0;
}
