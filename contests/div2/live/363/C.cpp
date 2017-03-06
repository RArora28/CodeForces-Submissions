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

int A[110], dp[110][5];

int rec(int i, int next) { 
  
  if(i == 0)
    return 0;
  
  else if(dp[i][next] != -1)  
    return dp[i][next];
  
  else {
    int T;
    
    T = rec(i-1, 0);
    
    if(next == 0)  {
      if(A[i] == 3)
	T = max(T, 1 + max(rec(i-1, 1),rec(i-1, 2)));
      else if(A[i] == 1) 
	T = max(T, 1 + rec(i-1, 2));
      else if(A[i] == 2) 
	T = max(T, 1 + rec(i-1, 1));
    }
      
    else if(next == 1) { 
      if(A[i] == 3 || A[i] == 1) 
	T = max(T, 1 + rec(i-1, 2));
    }
    
    else {
      if(A[i] == 3 || A[i] == 2) 
	T = max(T, 1 + rec(i-1, 1));
    }
    
    return dp[i][next] = T;
  }
}

int main() {

  int N, i;

  cin>>N;

  REP(i, N)
    cin>>A[i];
  
  SET(dp, -1);

  int Ans = rec(N, 0);
  
  Ans = max(Ans, max(rec(N, 1), rec(N, 2)));

  cout<<N-Ans<<endl;

  return 0;
}
