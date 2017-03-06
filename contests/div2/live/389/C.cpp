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

int X[N], Y[N];

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n;
  string s;
  
  cin>>n;
  cin>>s;

  int i;

  int px = 0, py = 0;
  int cx = 0, cy = 0;
  int steps = 0;
  int ans = 0;
  X[0] = 0;
  Y[0] = 0;
  
  rep(i, 0, n)
    {
      if(s[i] == 'L')
	X[i] = cx--;
      else if(s[i] == 'R')
	X[i] = cx++;
      else if(s[i] == 'U')
	Y[i] = cy++;
      else if(s[i] == 'D')
	Y[i] = cy--;
      steps++;
      
      if(steps > (abs(cx-px) + abs(cy-py)) )
	{
	  px = X[i-1];
	  py = Y[i-1];
	  ans++;
	  steps = 0;
	}
      X[i] = cx;
      Y[i] = cy;
    }
  
  ans++;
  cout<<ans<<endl;
  
  return 0;
}
