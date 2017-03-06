/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;
typedef vector<VI> adjList;

#define mod 1000000007
#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = b; i > a; i--)
#define REP(i, n) for(i = 1; i <= n; i++)
#define pr0(arr, n) rep(i, 0, n) cout<<arr[i]<<" "; cout<<endl;
#define pr1(arr, n) rep(i, 1, n+1) cout<<arr[i]<<" "; cout<<endl;
#define INF INT_MAX
#define gc getchar_unlocked
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))
#define gu getchar
#define pu putchar
#define SI(n) scanf("%d",&n)
#define PI(n) printf("%d\n",n)
#define SLL(n) scanf("%lld",&n)
#define PLL(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//fast io using cin/cout
//ios::sync_with_stdio(false);	cin.tie(NULL);

LL retLCA(LL a, LL b) { 
  
  while(a != b) { 
    if(a > b)
      a /= 2;
    else 
      b /= 2;
  }

  return a;
}

int main() {

  map<pair<LL, LL>, LL > m;

  LL q;

  cin>>q;

  LL opt;
  LL u, v, w;

  while(q--) { 
    
    cin>>opt;
    
    if(opt == 2) { 
      LL sum = 0;
      
      cin>>v>>u;
      
      LL temp = retLCA(u, v);
      
      //cout<<"HELLO"<<endl;
      
      while(v != temp) {
	if(m.count(MP(v/2, v)) > 0) 
	  sum += m[MP(v/2, v)];
	v /= 2;
      }
      
      while(u != temp) {
	if(m.count(MP(u/2, u)) > 0) 
	  sum += m[MP(u/2, u)];
	u /= 2;
      }
      
      cout<<sum<<endl;
    }

    else { 
      cin>>v>>u>>w;
      
      LL temp = retLCA(u, v);

      while(v != temp) {
	if(m.count(MP(v/2, v)) > 0) 
	  m[MP(v/2, v)] += w;
	else 
	  m[MP(v/2, v)] = w;
	v /= 2;
      }

      while(u != temp) {
	if(m.count(MP(u/2, u)) > 0) 
	  m[MP(u/2, u)] += w;
	else 
	  m[MP(u/2, u)] = w;
	u /= 2;
      }
    }
  }
  
  return 0;
}
