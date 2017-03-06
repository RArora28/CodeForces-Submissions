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

LL A[1000010], cum[1000010], distinct[1000010];

set<LL> p, s1;

int main() {

  ios::sync_with_stdio(false); cin.tie(NULL);
  bool flag = false;

  LL i, n;
  LL temp = 0;

  cin>>n;

  A[0] = 0;
  cum[0] = 0;
  distinct[0] = 0;
  bool start = false;

  rep(i, 1, n+1) {
    cin>>A[i];
    
    if(s1.count(A[i]) == 0) {
      temp++;
      s1.insert(A[i]);
    }
  }

  flag = false;
  LL temp1 = 0;

  rep(i, 1, n+1) {
    
    cum[i] = A[i] ^ cum[i-1];
    
    if(s.count(A[i]) == 0 && temp1 < temp) {
      
      temp1++;
      
      if(!start) {
	set<LL> s;
	start = true;
      }
      
      distinct[i] = distinct[i-1] ^ A[i];
      s.insert(A[i]);

      if(temp1 == temp)
	flag = true;
    }
    
    else {
      distinct[i] = distinct[i-1];
      
      if(flag) { 
	temp1 = 0;
	flag = false;
      }
  }
  
  LL m;
  LL l, r;

  rep(i, 1, n+1)
    cout<<i<<":"<<cum[i]<<" "<<distinct[i]<<endl;

  cin>>m;

  while(m--) { 
    cin>>l>>r;
    PLL(cum[r] ^ cum[l-1] ^ distinct[r] ^ distinct[l-1]);
  }
  return 0;
}
