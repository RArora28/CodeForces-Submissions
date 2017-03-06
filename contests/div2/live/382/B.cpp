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

double a[MAXSIZE];

int main() {

  int n, n1, n2;

  cin>>n>>n1>>n2;
  
  int i;

  rep(i, 1, n+1)
    cin>>a[i];

  sort(a+1, a+n+1);
  
  rep(i, 2, n+1)
    a[i] += a[i-1];

  double ans1 = (double(a[n]-a[n-n1])/(double)n1) + (double(a[n-n1]-a[n-n1-n2])/(double)n2);
  double ans2 = (double(a[n]-a[n-n2])/(double)n2) + (double(a[n-n2]-a[n-n1-n2])/(double)n1);
  
  printf("%0.7f\n", (double)max(ans1, ans2));

  return 0;
}
