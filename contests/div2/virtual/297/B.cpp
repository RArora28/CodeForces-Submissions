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

int c[2*MAXSIZE];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  string str;

  cin>>str;

  int l = str.size();
  
  int m;

  cin>>m;
  
  while(m--) {
    int x;
    cin>>x;
    c[x-1]++;
    c[l-x+1]--;
  }  

  int i;
  rep(i, 1, l)
    c[i] += c[i-1];

  i = 0;
  while(i < l) {
    if(c[i] % 2 == 1)
      cout<<str[l-1-i];
    else
      cout<<str[i];
    i++;
  }

  cout<<endl;
  
  return 0;
}
