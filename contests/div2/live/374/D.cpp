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


LL A[2*MAXSIZE];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n, k, x;

  cin>>n>>k>>x;

  LL i;
  LL MinNeg = 1, MaxNeg = 1, MinPos = 1, MaxPos = 1;;
  LL neg = 0;
  
  rep(i, 1, n+1) { 
    cin>>A[i];
    
    if(A[i] < 0) {
      neg++;
      
      if(A[i] < A[MinNeg])  
	MinNeg = i;
      if(A[i] > A[MaxNeg])
	MaxNeg = i;
    }
    
    else {
      if(A[i] < A[MinPos])  
	MinPos = i;
      if(A[i] > A[MaxPos])
	MaxPos = i;
    }
  }
  
  if(neg == 0) { 
    
    if((A[MinPos] - k*x) >= 0)
      A[MinPos] -= k*x;
    else {
      LL temp = k-(A[MinPos]/x+1);
      A[MinPos] -= (A[MinPos]/x + 1)*x;
      if(abs(A[MinPos]) > A[MaxPos] && temp > 0)
	 A[MinPos] -= temp*x;
      else if (temp > 0)
	A[MaxPos] += temp*x;
    }
  }

  else if(neg % 2 == 1 && k > 0) { 
    if(abs(A[MinNeg]) > A[MaxPos])
      A[MinNeg] -= k*x;
    else 
      A[MaxPos] += k*x;
  }
  
  else {
    if(A[MinPos] < abs(A[MaxNeg])) { 
      LL temp = k-(A[MinPos]/x+1);
      A[MinPos] -= (A[MinPos]/x + 1)*x;
      
      if(A[MinPos] < A[MinNeg] && temp > 0)
	MinNeg = MinPos;
      
      if(abs(A[MinNeg]) > A[MaxPos] && temp > 0)
	A[MinNeg] -= temp*x;
      else if(temp> 0)
	A[MaxPos] += temp*x;
    }
    else {
      LL temp = k-(abs(A[MaxNeg])/x+1);
      A[MaxNeg] += (abs(A[MaxNeg])/x + 1)*x;
      
      if(A[MaxNeg] > A[MaxPos])
	MaxPos = MaxNeg;
      
      if(abs(A[MinNeg]) > A[MaxPos] && temp > 0)
	A[MinNeg] -= temp*x;
      else if(temp > 0)
	A[MaxPos] += temp*x;
    } 
  }
  
  rep(i, 1, n+1)
    cout<<A[i]<<" ";

  cout<<endl;

  return 0;
}
