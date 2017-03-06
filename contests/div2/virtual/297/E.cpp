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

LL i;
LL fac[20], a[30];
LL n, k, ways = 0, S;
vector<LL> V;

void rec(LL ind, LL sum, LL K) { 
  if(sum > S)
    return;
  else if(K > k)
    return;
  else if(ind == n+1 ) {
    if(sum == S)
      ways++;
    return;
  }
  else ifS-sum][K-k] != -1);
  
  else
    {
      rec(ind+1, sum, K);
      if(a[ind] <= 18)
	rec(ind+1, sum + fac[a[ind]], K+1);
      rec(ind+1, sum+a[ind], K+1);
      return;
    }
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  fac[0] = 1;
  fac[1] = 1;
  
  rep(i, 2, 19)
    fac[i] = i*fac[i-1];
  
  cin>>n>>k>>S;
  
  rep(i, 1, n+1)
    cin>>a[i];
  
  //V mil gaya
  
  rec(1, 0, 0);
  cout<<ways<<endl;
  
  return 0;
}
