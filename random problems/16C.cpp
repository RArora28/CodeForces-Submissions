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
#define end "\n"

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

  ios::sync_with_stdio(false);	
  cin.tie(NULL);  

  LL a, b, x, y;
  
  cin>>a>>b>>x>>y;
  // if(a*b < x*y) {
  //   cout<<"hello"<<endl;
  //   cout<<"0 0"<<endl;
  //   return 0;
  // }

  LL g = __gcd(x, y);
  x /= g, y /= g;

  LL l = 1, u = 2e9, val, mid, t;
  LL i, j;

  if((a/x) > (b/y)) {
    
    t = b, val = y;
    bool ok = false;
    
    while(l <= u) { 
      //trace(i);
      mid = l + ((u-l)/2), i = val * mid, j = val * (mid+1);
      if((i <= t) && (j > t)) {
	ok = true;
	break;
      }
      else if(i < t) l = mid+1;
      else u = mid-1;
    }
    
    if(ok) 
      cout<<x*i/val<<" "<<i<<endl;
    else 
      cout<<"0 0"<<endl;
  }
  
  else {
    t = a, val = x;
    bool ok = false;
    
    while(l <= u) {
      //trace(i);
      mid = l + ((u-l)/2), i = val * mid, j = val * (mid+1);
      if((i <= t) && (j > t)) {
	ok = true;
	break;
      }
      else if(i < t) l = mid+1;
      else u = mid-1;
    }
    
    if(ok) 
      cout<<i<<" "<<y*i/val<<endl;
    else 
      cout<<"0 0"<<endl;
  }

  return 0;
}
