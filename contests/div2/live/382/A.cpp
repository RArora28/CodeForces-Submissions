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

  int n;
  int k;
  cin>>n>>k;

  string str;
  cin>>str;
  
  int i = 0;
  int x = 0, y = 0;

  for(auto it : str) { 
    if(it == 'G')
      x = i;
    else if(it == 'T')
      y = i;
    i++;
  }
  
  if( abs(y-x) % k != 0) 
    cout<<"NO"<<endl;
  else { 
    if(y < x) 
      swap(x, y);
    
    bool flag = true;
    while(x != y) {  
      if(str[x] == '#') {  
	flag = false;
	break;
      }
      x += k;
    }
    
    if(flag)
      cout<<"YES"<<endl;
    else 
      cout<<"NO"<<endl;
  }
  return 0;
}
