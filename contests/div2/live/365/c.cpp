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

LL c[100010], id[100010], cum[100010];

int main() {
  
  LL n, k;
  LL i;
  LL ans = 0;
  LL sum = 0;
  
  cin>>n>>k;

  rep(i, 1, n+1) { 
    
    cin>>c[i];
    
    if(i > 1) 
      ans += (c[i] * c[i-1]);
    
    sum += c[i];
  }
  
  ans += c[1] * c[n];
  
  LL sum2 = 0, sum3 = 0;
  
  rep(i, 0, k) {
    
    cin>>id[i];
    
    sum2 += c[id[i]];
    sum3 += c[id[i]]*c[id[i]];
    
    if(id[i] == 1)
      ans += (sum - c[1] - c[2] - c[n]) * c[1];
    else if(id[i] == n)
      ans += (sum - c[1] - c[n-1] - c[n]) * c[n];
    else 
      ans += (sum - c[id[i]] - c[id[i]-1] - c[id[i]+1]) * c[id[i]];

    //cout<<ans<<endl;
  }

  sort(id, id + k);
  
  sum2 = sum2*sum2 - sum3;
  sum2 /= 2;
  ans -= sum2;

  sum2 = 0;

  rep(i, 0, k-1) 
    if(id[i] == id[i+1]-1)
      sum2 += c[id[i]] * c[id[i+1]];
  
  if(id[0] == 1 && id[k-1] == n)
    sum2 += c[1]*c[n];
  
  cout<<(ans+sum2)<<endl;

  return 0;
}
