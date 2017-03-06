/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;
typedef vector<VI> adjList;

#define mod 1000000007
#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = b; i > a; i--)
#define REP(i, n) for(i = 1; i <= n; i++)
#define pr0(arr, n) rep(i, 0, n) cout<<arr[i]<<" "; cout<<endl;
#define pr1(arr, n) rep(i, 1, n+1) cout<<arr[i]<<" "; cout<<endl;
#define INF INT_MAX
#define gc getchar_unlocked
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))
#define gu getchar
#define pu putchar
#define SI(n) scanf("%d",&n)
#define PI(n) printf("%d\n",n)
#define SLL(n) scanf("%lld",&n)
#define PLL(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//fast io using cin/cout
//ios::sync_with_stdio(false);	cin.tie(NULL);

//maintaining the distinct trees

vector< VI > adj;
bool taken[200010], C;
int P[200010], parent[200010], size[200010];
int changes = 0;
int taken1[200010], P1[200010];

int Ap(int x) {
  if(parent[x] == x)
    return x;
  else 
    return parent[x] = Ap(parent[x]);
}

void dfs(int v) { 
  
  taken[v] = true;
  
  for(auto it : adj[v]) 
    if(!taken[it]) {
      parent[it] = Ap(v);
      size[parent[it]]++;
      dfs(it);
    }
  
  return;
}

void cycles(int v) { 
  
  taken1[v] = 1;
  
  if(C)
    return;
  
  for(auto it : adj[v]) {
    if(!taken1[it]) {
      dfs(it);
      P1[it] = v;
    }
    
    else if(taken1[it] && P1[v] != it) {
      C = true;
      
      if(adj[v].size() == 2) {
	P[v] = v;
	parent[v] = v;
      }

      else {
	P[it] = it;
	parent[it] = it;
      }
      
      changes++;
    }
  }
  
  return;
}

int main() {
  
  int N, i;
  
  cin>>N;
  
  adj.resize(N+1);
  
  rep(i, 1, N+1) { 
    cin>>P[i]; 
    if(P[i] != i) { 
      adj[P[i]].PB(i);
      adj[i].PB(P[i]);
    }
  }
  
  //checking cycles
  
  rep(i, 1, N+1) {
    
    C = false;
    
    if(!taken1[i]) 
      cycles(i);
    
    cout<<C<<endl;
  }
  
  cout<<endl;
  //making trees;
  
  rep(i, 1, N+1) { 
    if(!taken[i] && P[i] == i) {
      parent[i] = i;
      dfs(i);
    }
  }
  
  int Min = INT_MAX, baap = -1;

  rep(i, 1, N+1) {
    cout<<size[i]<<" ";
    if(size[i] < Min && size[i] > 0) { 
      Min = size[i];
      baap = i;
    }
  }
  
  rep(i, 1, N+1)  
    if(P[i] == i && i != baap) {
      P[i] = baap;
      changes++;
    }

  cout<<changes<<endl;

  rep(i, 1, N+1)
    cout<<P[i]<<" ";

  cout<<endl;

  return 0;
}
