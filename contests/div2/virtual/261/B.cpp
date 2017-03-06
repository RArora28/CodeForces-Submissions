/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 200005
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

  int i; 

  int a[MAXSIZE];

  rep(i, 1, N+1)
    cin>>a[i];

  bool dif = false;

  sort(a+1, a+N+1);

  rep(i, 1, N)
    if(a[i] != a[i+1])
      dif = true;

  if(!dif) 
    cout<<"0 "<<(LL)N*(LL)(N-1)/2<<endl;
  else { 
    int count1=1 , count2 = 1;
    i = 1;
    while(a[i] == a[i+1]) i++, count1++;
    i = N;
    while(a[i] == a[i-1]) i--, count2++;
    cout<<a[N]-a[1]<<" "<<(LL)count1 * (LL)count2<<endl;
  }
			    
  
  return 0;
}
