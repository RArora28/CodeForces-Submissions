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
  
  int N;

  cin>>N;

  char arr[150];

  VI v;

  int c1 = 0, c2 = 0;
  int i;

  cin>>arr;

  if(arr[0] == 'W')
    c2 = 0;
  else 
    c2 = 1;

  rep(i, 1, N) { 
    if(arr[i] == 'W') {
      if(arr[i-1] == 'B') {
	v.PB(c2);
	c1++;
      }
      c2 = 0;
    }
    else 
      c2++;
  }

  if(arr[N-1] == 'B') {
    v.PB(c2);
    c1++;
  }
  
  cout<<c1<<endl;
  
  for(auto it : v)
    cout<<it<<" ";

  if(c1 != 0)
    cout<<endl;

  return 0;
}
