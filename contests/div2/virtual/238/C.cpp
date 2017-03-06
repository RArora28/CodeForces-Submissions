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

int Ans[1500][3][3], row[1500], col[1500], A[1500][1500], B[1500][1500];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int i, j, n;

  cin>>n;

  rep(i, 1, n+1)
    rep(j, 1, n+1) {
    cin>>A[i][j];
    B[i][j] = 1-A[i][j];
  }
  
  rep(i, 1, n+1)
    rep(j, 1, n+1) 
    Ans[i][0][0] ^= A[i][j]*A[j][i]; 
  
  rep(i, 1, n+1)
    rep(j, 1, n+1) {
    if(j == i)
      Ans[i][0][1] ^= B[i][i]*B[i][i];
    else 
      Ans[i][0][1] ^= A[i][j]*B[j][i]; 
  }

  rep(i, 1, n+1)
    rep(j, 1, n+1) {
    if(j == i)
      Ans[i][1][0] ^= B[i][i]*B[i][i];
    else 
      Ans[i][1][0] ^= B[i][j]*A[j][i]; 
  }
  
  rep(i, 1, n+1)
    rep(j, 1, n+1) { 
    if(j == i)
      Ans[i][1][1] ^= A[i][i]*A[i][i];
    else 
      Ans[i][1][1] ^= B[i][j]*B[j][i]; 
  }
  int a = 0;
  int x, opt;

  rep(i, 1, n+1)
    a ^= Ans[i][0][0];

  int q;
  cin>>q;
  string str;

  while(q--) { 
    cin>>opt;
    
    if(opt == 3) {
      if(a == 1)
	str += '1';
      else 
	str += '0';
    }

    else if(opt == 1) { 
      cin>>x;
      a ^= Ans[x][row[x]][col[x]];
      row[x] = 1 - row[x];
      a ^= Ans[x][row[x]][col[x]];
    }
    else {
      cin>>x;
      a ^= Ans[x][row[x]][col[x]];
      col[x] = 1 - col[x];
      a ^= Ans[x][row[x]][col[x]];
    }
  }
  
  cout<<str<<endl;

  return 0;
}
