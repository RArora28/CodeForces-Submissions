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
LL a;
LL ind, i;
LL dis[100010];
LL n;
bool flag = false;
LL y;

int main() { 

  LL Min = INT_MAX;
  LL Max = INT_MIN;
  LL count1 = 0;
  LL count2 = 0;
  
  ios::sync_with_stdio(false);	cin.tie(NULL);

  cin>>n>>a;

  rep(i, 1, n+1) {
    cin>>dis[i]; 
    if(dis[i] == a)
      flag= true;
    
    if(dis[i] < a)
      count1++;
    else if(dis[i] > a)
      count2++;

    Min = min(Min, dis[i]);
    Max = max(Max, dis[i]);
  }

  sort(dis+1, dis+1+n);
  LL ans;

  if(n == 1)
    cout<<"0"<<endl;
  
  else if(n == 2)
    cout<<min(abs(dis[2]-a), abs(dis[1]-a))<<endl;

  else if(!flag) {
    if(a > Max) 
      cout<<abs(a-dis[2])<<endl;
    
    else if(a < Min )
      cout<<abs(dis[n-1]-a)<<endl;

    else if(count1 == 1) {
      ans = min(abs(dis[n]-a), abs(abs(dis[n-1]-a)+abs(dis[n-1]-dis[1])));
      ans = min(ans, abs(abs(a - dis[1]) + abs(dis[n-1]-dis[1])));
      cout<<abs(ans)<<endl;
    }
    
    else if(count2 == 1) {
      ans = min(abs(a-dis[1]), abs(abs(dis[2]-a)+abs(dis[n]-dis[2])));
      ans = min(ans, abs(abs(a - dis[n]) + abs(dis[n]-dis[2])));
      cout<<abs(ans)<<endl;
    }

    else 
      cout<<abs(min(abs(abs(dis[n]-a) + abs(dis[n]-dis[2])), abs(a-dis[1] + dis[n-1]-dis[1])))<<endl;
  }
      
  else if(flag) {
    
    if(a == Max) 
      cout<<abs(a-dis[3])<<endl;

    else if(a == Min)
      cout<<abs(dis[n-2]-a)<<endl;

    else if(count1 == 1) {
      ans = min(abs(dis[n-1]-a), abs(dis[n-2]-a+dis[n-2]-dis[1]));
      ans = min(ans, abs(a - dis[1] + dis[n-2]-dis[1]));
      cout<<abs(ans)<<endl;
    }

    else if(count2 == 1) {
      ans = min(abs(a-dis[2]), abs(abs(dis[3]-a)+abs(dis[n]-dis[3])));
      ans = min(ans, abs(abs(a - dis[n]) + abs(dis[n]-dis[3])));
      cout<<abs(ans)<<endl;
    }

    else 
      cout<<abs(min(abs(dis[n-1]-a + dis[n-1]-dis[1]), abs(a - dis[2] + dis[n] - dis[2])))<<endl; 
  } 
      
  return 0;
}
