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

LL a, b , c, d, e;
LL sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0 ;

LL f(int x) { 
  
  sum5 += (x/e);
  x -= ((x/e) * e);
  sum4 += (x/d);
  x -= ((x/d) * d);
  sum3 += (x/c);
  x -= ((x/c)*c);
  sum2 += (x/b);
  x -= ((x/b)*b);
  sum1 += (x/a);
  x -= ((x/a) * a);

  //trace(x);
  return x;
}


int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n; 

  cin>>n;

  LL i;
  LL p[100];

  rep(i, 1, n+1)
    cin>>p[i];
  
  cin>>a>>b>>c>>d>>e;

  LL x = 0;
  
  rep(i, 1, n+1) { 
    x += p[i];
    x = f(x);
  }
  
  cout<<sum1<<" "<<sum2<<" "<<sum3<<" "<<sum4<<" "<<sum5<<endl;
  cout<<x<<endl;
  
  return 0;
}
