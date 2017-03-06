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

bool taken[100][100];
char A[100][100];
map<II, VII> M;
multiset<pair<int, II > > S;
int I, J;
int n, m, k;

bool dfs(int i, int j) {
  taken[i][j] = true;
  M[MP(I,J)].PB(MP(i, j));
  
  if( (((i+1) == n) && (A[i+1][j] == '.')) ||  (((j+1) == m) && (A[i][j+1] == '.')) ||  (((i-1) == 1) && (A[i-1][j] == '.')) ||  (((j-1) == 1) && (A[i][j-1] == '.')))
    return false;
  
  bool temp = true;
    
  if(A[i+1][j] == '.' && !taken[i+1][j])
    temp &= dfs(i+1, j);
  if(A[i][j+1] == '.' && !taken[i][j+1])
    temp &= dfs(i, j+1);
  if(A[i-1][j] == '.' && !taken[i-1][j])
    temp &= dfs(i-1, j);
  if(A[i][j-1] == '.' && !taken[i][j-1])
    temp &= dfs(i, j-1);
  return temp;
}

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int i, j;
  int count = 0;

  cin>>n>>m>>k;
  
  rep(i, 1, n+1)
    rep(j, 1, m+1)
    cin>>A[i][j];
  
  rep(i, 2, n) 
    rep(j, 2, m)
    if((A[i][j] == '.') && !taken[i][j]) {
      I = i, J = j;
      if(dfs(i ,j )) {
	count++;
	S.insert(MP(M[MP(i, j)].size(), MP(i, j)));
      }
    }
  
  int ans = 0;
  
  trace(count);
  
  for(auto it : S) {
    if(count == k)
      break;
    else {
      i = it.S.F, j = it.S.S;
      
      for(auto itr : M[MP(i, j)]) {
	A[itr.F][itr.S] = '*';
	ans++;
      }
      count--;
    }
  }
  
  trace(count);

  cout<<ans<<endl;
  
  rep(i, 1, n+1) {
    rep(j, 1, m+1)
      cout<<A[i][j];
    cout<<endl;
  }


  return 0;
}
  
