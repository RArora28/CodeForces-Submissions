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

LL dp1[100010], dp2[100010];
bool ok = true;
vector<string> S1, R;
LL i, n;
LL C[100010], cost = 0;

int main() {

  cin>>n;
  
  rep(i, 1, n+1) 
    dp1[i] = dp2[i] = INT_MAX*1e6;
  
  S1.resize(n+1);
  R.resize(n+1);
  
  rep(i, 1, n+1)
    cin>>C[i];
  
  rep(i, 1, n+1) { 
    cin>>S1[i];
    R[i] = S1[i];
  }
  
  rep(i, 1, n+1) 
    reverse(R[i].begin(), R[i].end());
  
  dp1[1] = 0;
  dp2[1] = C[1];

  rep(i, 2, n+1) {
    
    if(S1[i] >= S1[i-1])
      dp1[i] = min(dp1[i], dp1[i-1]);
    if(S1[i] >= R[i-1])
      dp1[i] = min(dp1[i], dp2[i-1]);
    if(R[i] >= S1[i-1])
      dp2[i] = min(dp2[i], C[i] + dp1[i-1]);
    if(R[i] >= R[i-1])
      dp2[i] = min(dp2[i], C[i] + dp2[i-1]);
  }
  
  LL cost = min(dp1[n], dp2[n]);
  
  if(cost > 1e15)
    cost = -1;
  
  cout<<cost<<endl;

  return 0;
}
