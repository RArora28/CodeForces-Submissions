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

LL C[10*MAXSIZE];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n, ans = 0;
  
  cin>>n;
  
  while(n--) {
    LL x;
    cin>>x;
    C[x]++;
  }
  
  LL i;
  
  rev(i, 1e6+1, 0) 
    if( (C[i] % 2 == 1) && (C[i-1] != 0) )
      {
	C[i]--;
	C[i-1]++;
      }
  
  queue<LL> S;
  
  rev(i, 1e6+1, 0)
    while(C[i] > 1)
      {
	if( (S.size() != 0) )
	  {
	    ans += (LL)S.front()*i;
	    S.pop();
	  }
	
	else 
	  S.push(i);
	C[i] -= 2;
      }
  
  cout<<ans<<endl;
      
  return 0;
}
