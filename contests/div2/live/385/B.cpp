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

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n, m;

  cin>>n>>m;

  int l = INT_MAX, r = -1, u = INT_MAX, d = -1;

  int i, j;
  int cnt = 0;
  char ch;
  
  rep(i, 1, n+1)
    {
      rep(j, 1, m+1)
	{
	  cin>>ch;

	  if(ch == 'X')
	    {
	      cnt++;
	      l = min(l, j);
	      r = max(r, j);
	      u = min(u, i);
	      d = max(d, i);
	    }
	}
    }

  if( cnt == 1 || cnt == ((r-l+1)*(d-u+1)) )
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}
