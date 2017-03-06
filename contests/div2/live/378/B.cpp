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

LL l[100010], r[100010];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL N;
  LL L = 0;
  LL R = 0;

  cin>>N;

  LL i;
  
  rep(i, 1, N+1)  { 
    cin>>l[i]>>r[i];
    L += l[i];
    R += r[i];
  }
  
  LL ans = abs(L - R);
  LL k = 0;

  // trace(ans);

  rep(i, 1, N+1) { 
    if( abs(L - R  - 2*l[i] + 2*r[i] ) > ans) {
      //trace(abs( L - R + 2*l[i] - 2*r[i]));
      ans = abs( L - R - 2*l[i] + 2*r[i]);
      k = i;
    }
  }

  cout<<k<<endl;

  return 0;
}
