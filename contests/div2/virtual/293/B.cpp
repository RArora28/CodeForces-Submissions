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

int C1[100], C2[100], c1[100], c2[100];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  string s,t ;

  cin>>s;
  cin>>t;

  int i;
  
  rep(i, 0, (int)s.size() )
    {
      if(s[i] >= 'a' && s[i] <= 'z')
	c1[s[i]-'a']++;
      else
	c2[s[i]-'A']++;
    }
  
  rep(i, 0, (int)t.size() )
    {
      if(t[i] >= 'a' && t[i] <= 'z')
	C1[t[i]-'a']++;
      else
	C2[t[i]-'A']++;
    }
  
  int yay = 0, whoops = 0;
  
  rep(i, 0, 26)
    {
      yay += min(c1[i], C1[i]);
      c1[i] -= min(c1[i], C1[i]);
      C1[i] -= min(c1[i], C1[i]);
      yay += min(c2[i], C2[i]);
      c2[i] -= min(c2[i], C2[i]);
      C2[i] -= min(c2[i], C2[i]);
    }
  
  rep(i, 0, 26)
    {
      whoops += min(c1[i], C2[i]);
      c1[i] -= min(c1[i], C2[i]);
      C2[i] -= min(c1[i], C2[i]);
      whoops += min(c2[i], C1[i]);
      c2[i] -= min(c2[i], C1[i]);
      C1[i] -= min(c2[i], C1[i]);
    }
  
  cout<<yay<<" "<<whoops<<endl;
  
  
  return 0;
}
