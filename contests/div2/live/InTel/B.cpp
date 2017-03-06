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

int retCount(string str) {
  
  int len = str.size();
  int c = 0;
  int i = 0;
  
  //trace(str);

  while(i < len) {
    if(str[i] == 'a' || str[i] == 'e' ||str[i] == 'i' || str[i] == 'o' ||str[i] == 'u' ||str[i] == 'y')
      c++;
    i++;
  }

  return c;
}

int main() {

  string str;

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int i;
  int n;
  bool ok = true;
  
  cin>>n;
  
  int p[200];
  
  rep(i, 0, n)
    cin>>p[i];
  
  getline(cin, str);

  rep(i, 0, n) {
    getline(cin, str);
    
    if(p[i] != retCount(str)) {
      //cout<<str<<endl;
      //cout<<retCount(str)<<endl;
      //cout<<i<<endl;
      ok = false;
    }
  }

  if(ok)
    cout<<"YES"<<endl;
  else 
    cout<<"NO"<<endl;
  
  return 0;
}
