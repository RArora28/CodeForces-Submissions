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

int cnt[500];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int n, k;
  cin>>n>>k;

  string s[500], str;
  
  int i;
  
  rep(i, 1, n+1) {
    cin>>s[i];
    cnt[(int)s[i].size()]++;
  }
  
  cin>>str;
  
  int len = str.size();
  
  int a= 0;

  rep(i, 1, n+1)
    if(str == s[i])
      a++;

  int Min = 0;
  
  rep(i, 0, 300)  {
    if(i < len)  
      Min += cnt[i];
    else break;
  }
  
  //trace(Min);
  int Max = Min;
  
  Min += (Min/k)*5;
  Min += 1;
  
  Max += (cnt[str.size()]-a);
  Max += (Max / k)*5;

  Max += 1;

  cout<<Min<<" "<<Max<<endl;

  return 0;
}
