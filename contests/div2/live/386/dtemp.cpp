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

  int n, k, a, b;
  int i;
  
  cin>>n>>k>>a>>b;

  if(a == 0 || b == 0)
    {
      if(a == 0)
	{
	  if(k >= n)
	    {
	      rep(i, 1, n+1)
		cout<<"B";
	      cout<<endl;
	    }
	  else
	    {
	      cout<<"NO"<<endl;
	    }
	}
      else
	{
	  if(k >= n)
	    {
	      rep(i, 1, n+1)
		cout<<"G";
	      cout<<endl;
	    }
	  else
	    {
	      cout<<"NO"<<endl;
	    }
	}
    }

  else if ()
    {
      int M = max(a, b);
      int m = min(a, b);
      
    }
  // else if( (int)max(a, b)/(int)min(a, b) <= k)
  //   {
  //     int K = (int)max(a, b)/(int)min(a, b);
      
  //     if(a > b)
  // 	{
  // 	  while(b != 0)
  // 	    {
  // 	      rep(i, 0, K)
  // 		cout<<"G";
  // 	      cout<<"B";
  // 	      b--;
  // 	      a -= K;
  // 	    }
  // 	  while(a != 0)
  // 	    {
  // 	      cout<<"G";
  // 	      a--;
  // 	    }
  // 	  cout<<endl;
  // 	}
  //     else
  // 	{
  // 	  while(a != 0)
  // 	    {
  // 	      rep(i, 0, K)
  // 		cout<<"B";
  // 	      cout<<"G";
  // 	      a--;
  // 	      b -= K;
  // 	    }
  // 	  while(b != 0)
  // 	    {
  // 	      cout<<"B";
  // 	      b--;
  // 	    }
  // 	  cout<<endl;
  // 	}
  //   }
  // else
  //   {
  //     string str;
      
  //     if(a > b)
  // 	{
	  
  // 	}
  //   }
  return 0;
}
