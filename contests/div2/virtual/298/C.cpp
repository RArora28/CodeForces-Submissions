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

LL d[2*MAXSIZE], Ans[2*MAXSIZE];

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n, A;
  LL i;
  
  cin>>n>>A;

  LL s = 0;
  
  rep(i, 1, n+1)
    {
      cin>>d[i];
      s += d[i];
    }
  
  rep(i, 1, n+1)
    {
    
      LL a = min((LL)d[i], (LL)(A-n+1) );
      LL b = max((LL)1, (LL)(A-s+d[i]) );
      Ans[i] = a-b+1;
    }
  
  rep(i, 1, n+1)  
    cout<<d[i]-Ans[i]<<" ";;

  cout<<endl;
  
  return 0;
}
