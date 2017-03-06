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
  
  int i , N;

  char str[10];
  
  cin>>N;
  cin>>str;

  if(N == 24) { 
    int temp1 = (str[3]-'0')*10 + (str[4]-'0');
    int temp2 = (str[0]-'0')*10 + (str[1]-'0');
   
    if(temp1 >= 60) 
      str[3] = '1';
    if(temp2 >= 24)
      str[0] = '1';
  }
  else {

  int temp1 = (str[3]-'0')*10 + (str[4]-'0');
  int temp2 = (str[0]-'0')*10 + (str[1]-'0');
   
    if(temp1 >= 60) 
      str[3] = '1';
    if(temp2 > 12) {
      if(str[1] != '0')
	str[0] = '0';
      else {
	str[0] = '1';
      }
    }
    else if(temp2 == 0)
      str[0] = '1';
  }

  cout<<str<<endl;

  return 0;
}
