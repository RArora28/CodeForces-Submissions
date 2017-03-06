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


double s, x1, x2, t1, t2, p, d;

double Min(double a, double b)
{
  if(a < b)
    return a;
  else
    return b;
}

//d = 1
double f1(double x1, double x2)
{
  if( p <= x1)
    return Min(abs(x2-x1)*t2, abs(x2-p)*t1);
  else
    return Min(abs(x2-x1)*t2, ( abs(s-p)+abs(s)+abs(x2))*t1);
}

//d = -1
double f2(double x1, double x2)
{
  return Min(abs(x2-x1)*t2, (p + x2) *t1);
}

//d = -1
double F1(double x1, double x2)
{
  if( p >= x1)
    return Min(abs(x2-x1)*t2, abs(x2-p)*t1);
  else
    return Min(abs(x2-x1)*t2, ( p + s + s-x2 )*t1);
}

//d = 1
double F2(double x1, double x2)
{
  return Min(abs(x2-x1)*t2, ( abs(s-p)+abs(s-x2))*t1);
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  cin>>s>>x1>>x2;
  cin>>t1>>t2;
  cin>>p>>d;

  if(x1 <= x2)
    {
      if( d == 1)
	cout<<f1(x1, x2)<<endl;
      else
	cout<<f2(x1, x2)<<endl;
    }

  else
    {
      if( d == 1)
	cout<<F2(x1, x2)<<endl;
      else
	cout<<F1(x1, x2)<<endl;
    }
  return 0;
}
