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

set<int>I;

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int N;
  cin>>N;

  int i;
  int x;

  rep(i, 1, N+1) { 
    cin>>x;
    I.insert(x);
  }

  while(1) { 

    set<int>::iterator it = I.end();
    it--;
    
    x = *it;
    int y = x, ans;
    bool ok = false;

    while(y > 0) { 
      if(I.count(y) == 0) {
	ans = y;
	ok = true;
	break;
      }
      y /= 2;
    }

    if(!ok)
      break;
    else {
      I.insert(ans);
      I.erase(x);
    }
  }

  for(auto it :I)
    cout<<it<<" ";

  cout<<endl;

  return 0;
}
