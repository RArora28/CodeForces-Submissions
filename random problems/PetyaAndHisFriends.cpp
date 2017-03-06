/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<unsigned long long> VI;
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
#define end "\n"

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

bool B[1000010];
LL A[1000010];
VI primes;

void sieve(LL N) {
  
  LL i, j;

  rep(i, 2, sqrt(N)+1)  
    for(j = 2; i*j <= N; j++)
      B[i*j] = true;
 
  rep(i, 2, N+1) 
    if(!B[i])
      primes.PB(i);
}
int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
 
  LL N;

  cin>>N;
  
  if(N == 2) {
    cout<<"-1"<<endl;
    return 0;
  }

  sieve(1e6);
  
  LL k;
  
  rep(k ,1, 100)
    A[k] = 1;
  
  LL i, j;

  LL ind = 0;

  rep(i, 1, N+1) {
    LL a = primes[ind];
    rep(j, 1, N+1) {
      if(j != i)
	A[j] *= (LL)a;
    }
    ind++;
  }

  rep(i, 1, N+1)
    cout<<A[i]<<endl;

  return 0;
}
