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

LL a[5000];
map<LL, LL> b;

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n, m;
  vector<LL> ind;
  LL i;

  cin>>n>>m;

  rep(i, 1, m+1)
    b[i] = 0;

  rep(i, 1, n+1) {
    cin>>a[i];
    if(b.find(a[i]) != b.end())
      b[a[i]]++;
    else 
      b[a[i]] = 1;
    
    if(a[i] > m)
      ind.PB(i);
  }
  
  LL ini = 0;
  LL Min = n/m;
  
  for(auto it : b)   
    if(it.F <= m) 
      if(it.S < Min)
	ini += Min - it.S;
  
  //for(auto it : ind)
  //trace(it);

  for(auto &it : b)
    if(it.F <= m && it.S > Min) {
      for(i = 1; i <= n; i++) {
	if(a[i] == it.F) {
	  b[it.F]--;
	  ind.PB(i);
	}
	if(it.S == Min)
	  break;
      }
    }
  
  LL k = 0;
  
  for(auto &it : b) { 
    if(it.F <= m) { 
      while(it.S < Min) {
	a[ind[k++]] = it.F;
	it.S++;
      }
    }
  }
  
  cout<<Min<<" "<<ini<<endl;
  
  rep(i, 1, n+1)
    cout<<a[i]<<" ";
  
  cout<<endl;

  return 0;
}
