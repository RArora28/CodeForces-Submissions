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

const int N = 1e5+10;

int p[N], c[N], SZ[N], e[N];
bool ok[N];

int find(int x)
{
  if ( x == p[x])
    return x;
  else return p[x] = find(p[x]);
}

void U(int a, int b)
{
  int A = find(a);
  int B = find(b);

  if(A == B)
      e[A]++;
  else {
    if(SZ[A] > SZ[B])
      {
	p[B] = A;
	SZ[A] += SZ[B];
	e[A] += (1 + e[B]);
      }
    else
      {
	p[A] = B;
	SZ[B] += SZ[A];
	e[B] += (1 + e[A]);
      }
  }
  return;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n, m, k;
  int i;
  
  cin>>n>>m>>k;
  
  rep(i, 1, n+1)
    {
      p[i] = i;
      e[i] = 0;
      SZ[i] = 1;
    }
  
  rep(i, 1, k+1)
    cin>>c[i];

  int a, b;
  
  rep(i, 1, m+1)
    {
      cin>>a>>b;
      U(a, b);
    }

  int ans = 0;
  int max = -1;
  int x = 1;
  
  rep(i, 1, k+1)
    {
      int K = find(c[i]);

      if(SZ[K] > max)
	{
	  max = SZ[K];
	  x = K;
	}
    }

  rep(i, 1, k+1)
    {
      int K = find(c[i]);
      if(K != x)
	{
	  ok[K] = true;
	  ans += (((SZ[K])*(SZ[K]-1))/2) - e[K];
	}
    }

  int S = 0, E = 0;

  //trace(x, SZ[x], e[x]);
  
  rep(i, 1, n+1)
    {
      int K = find(i);
      //trace(i, K, ok[K]);
      if(ok[K] == false)
	{
	  ok[K] = true;
	  S += SZ[K];
	  E += e[K];
	}
    }

  //trace(S, E);
  
  ans += (((S)*(S-1))/2) - E;

  cout<<ans<<endl;
  
  return 0;
}
