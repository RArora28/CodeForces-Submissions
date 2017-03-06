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

LL paw(LL a, LL b) { 
  
  LL ans = 1;
  
  while(b > 0) { 
    if(b & 1) { 
      ans *= (a % mod);
      ans %= mod;
    }

    a *= (a % mod);
    a %= mod;
    b >>= 1;
  }

  return ans;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  LL A, B, n, x;

  cin>>A>>B>>n>>x;

  if(A == 1) { 
    cout<<((x % mod) + (((n % mod) * (B % mod)) % mod)) % mod<<endl;
    return 0;
  }
  LL S1 = (paw(A, n) * (x % mod)) % mod;
  LL S2 = ((B % mod)*((((paw(A, n) % mod + mod - 1) % mod) * paw(A-1, mod-2)) % mod)) % mod;
  cout<<(S1 + S2) % mod;
  return 0;
}
