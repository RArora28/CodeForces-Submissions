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

int main() {

  double n, p, t;

  cin>>n>>p>>t;
  
  int i;
  double a = 1;
  double b = 1-p;
  
  rep(i, 1, t)
    a *= (double)b;

  trace(a);
  double ans1 = p*a*t, ans = ans1;

  trace(ans1);
  
  rep(i, 2, min(t, n) + 1)
    {
      ans1 *= (double)p;
      ans1 *= (double)(t-(double)i);
      ans1 /= (double)(1-p);
      ans1 /= (double)2;
      ans += (double)ans1*(double)i;
    }

  cout<<ans<<endl;
  
  return 0;
}
