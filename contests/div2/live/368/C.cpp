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
#define rev(i, a, b) for(i = b; i > a; i--)x
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

int main() {

  LL n;

  LL i, x, y;
  cin>>n;

  LL a = -1, b = -1;

  bool prime = false;
  
  int u = sqrt(n)+1;
  
  if(u != 1)
    rep(i, 2, u)
      if(n % i == 0)
	prime= true;
  
  if(n % 2 == 0) {

    //cout<<"hello"<<endl;
    
    n /= 2;
    x = n;
    y = 1;
    a = x*x - y*y;
    b = x*x +y*y;
  }

  else if(!prime) {
    x = n;
    y = 1;
    a = x*x - y*y;
    b = x*x +y*y;
    a /= 2;
    b /= 2;
  }
  
  else {

    //case 1: x^2 + y^2
    
    LL temp = sqrt(n)+1;
    LL A;
    double B, C;
    rep(i, 1, temp) {
      C = (double)n*n - (double)i*i;
      A = (LL)sqrt(C);
      B = (double)sqrt(C);
      
      if(A == B) {
	a = 2*i*(n-i);
	b = max(n-i, i)*max(n-i, i) - min(n-i, i)* min(n-i, i);
	break;
      }
    }

    //case 2:
    
    vector<LL> factors;

    rep(i, 1, temp) 
      if(n % i == 0) {
	factors.PB(i);
	factors.PB(n/i);
      }

    for(auto it1 : factors) {
      for(auto it2 : factors) {
	LL Max = max(it1, it2);
	LL Min = min(it1, it2);

	if((Max-Min) * (Max + Min) == n) {
	  a = 2*Max*Min;
	  b = Max * Max + Min*Min;
	  break;
	}
      }
    }
  }
  
  if(a > b)
    swap(a, b);
  
  if(a <= 0 || b <= 0)
    cout<<"-1"<<endl;
  else 
    cout<<a<<" "<<b<<endl;

  return 0;
}
