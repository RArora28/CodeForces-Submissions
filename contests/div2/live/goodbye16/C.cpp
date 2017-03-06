/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

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

const int N = 2e5+10;
const int mod = 1e9+7;

int d[N], diiv[N];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int i;
  bool one = false, two = false;

  int n;

  cin>>n;

  rep(i, 1, n+1)
    {
      cin>>d[i]>>diiv[i];

      if(diiv[i] == 1)
	one = true;
      else if(diiv[i] == 2)
	two = true;
    }

  if(two == false)
    {
      cout<<"Infinity"<<endl;
      return 0;
    }
  else if(one == false)
    {
      cout<<d[n]+1899<<endl;
      return 0;
    }
  else
    {
      bool ok = true, o = false, t = false;
      int r = 0;
      int ans = 0;
      int s = 0;

      s += d[1];

      if(diiv[1] == 1)
	o = true;
      else if(diiv[1] == 2)
	t = true;
	
      rep(i, 2, n+1)
	{
	  if(diiv[i] == 1)
	    o = true;
	  else if(diiv[i] == 2)
	    t = true;
	  if(o == true && (s >= 0) && diiv[i] == 2)
	    ok = false;
	  else if( t == true && (s < 0) && diiv[i] == 1)
	    ok = false;
	  ans += d[i];
	}

      if(diiv[n] == 2)
	ans += d[n];
      
      if(!ok)
	cout<<"Impossible"<<endl;
      else
	cout<<ans<<endl;
    }
  return 0;
}
