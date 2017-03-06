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
  
  vector<string> g1, g2;
  string str;
  
  int n;
  cin>>n;

  cin>>str;
  
  int i ;

  string temp;
  bool bracket = false;
  
  for(auto it : str) { 
    if(it == '_' || it == ')') {
      if(temp.size() > 0) {
	if(bracket) 
	  g1.PB(temp);
	else
	  g2.PB(temp);
      }
      temp.clear();
      if(it == ')')
	bracket = false;
    }
    else if(it == '(') {
      if(temp.size() > 0) {
	if(bracket) 
	  g1.PB(temp);
	else
	  g2.PB(temp);
      }
      temp.clear();
      
      bracket = true;
    }
    else 
      temp += it;
  }
  
  if(str[str.size()-1] != '_' && str[str.size()-1] != ')')
    g2.PB(temp);
  int M = 0;
  
  rep(i, 0, (int)g2.size())
    if((int)g2[i].size() > M)
      M = g2[i].size();

  cout<<M<<" "<<g1.size()<<endl;
  return 0;
}
