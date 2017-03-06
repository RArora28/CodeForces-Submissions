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


VI primes;
LL no[1000010];

void sieve(LL n) {  //complexity of O(nloglog(n))
  LL i, j;
  no[0] = no[1] = 1;
  LL temp = sqrt(n+1);
  rep(i, 2, temp+1) 
    for(j = 2; i*j <= n; j++) 
      no[i*j] = 1;
  
  rep(i, 2, n+1)
    if(no[i] == 0)
      primes.PB(i);
}

bool isPrime(LL m)  {  //considering very large 'n', complexity of O(sqrt(n)/ln(sqrt(n)))
  if(m <= 1e6)
    return 1-no[m];
  else {
    int i = 0;
    while(i < (LL)primes.size() && primes[i++] <= sqrt(m)) 
      if(m % primes[i-1] == 0)
	return false;
    return true;
  }
}

int main() {

   ios::sync_with_stdio(false);	
   cin.tie(NULL);
 
  LL n;

  cin>>n;
  
  if(n == 2)
    cout<<"1"<<endl;
  else if(n % 2 == 0) 
    cout<<"2"<<endl;
  else {
    sieve(1e6);
    if(isPrime(n))
      cout<<"1"<<endl;
    else if(isPrime(n-2))
      cout<<"2"<<endl;
    else 
      cout<<"3"<<endl;
  }
  
  return 0;
}
