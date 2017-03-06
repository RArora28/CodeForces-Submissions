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

LL popcount(LL x) {

  LL count = 0;

  while(x > 0) {
    if(x & 1)
      count++;
    x >>= 1;
  }
  
  return count;
}

LL Length(LL x) {

  LL count = 0;

  while(x > 0) {
    count++;
    x >>= 1;
  }

  return count;
}

LL f1(LL count) {

  LL Num = 0;

  while(count--) 
    Num = 2*Num + 1;
  
  return Num;
}

int main() {

  LL n;
  LL len1, len2, set2;
  LL ans;
  cin>>n;

  while(n--) { 
    
    LL l, r;
    vector<LL> L, R;
    LL i;

    cin>>l>>r;
    
    len1 = Length(l), len2 = Length(r), set2 = popcount(r);

    if(len2 == set2)
      ans = r;
    
    else if(len1 == len2) {
      
      if(len1 == 0 && len2 == 0) 
	ans = 0;

      else {
	LL re = r;
	ans = 0;

	while(l > 0) {
	  L.PB(l%2);
	  l /= 2;
	}

	while(r > 0) {
	  R.PB(r%2);
	  r /= 2;
	}

	LL count = 0;
	bool flag = true;
	bool flag1 = true;

	for(i = L.size()-1; i >= 0; i--) {

	  if(L[i] == 0 && R[i] == 1 && flag) {
	    R[i] = 0;
	    flag = false;
	  }

	  if(flag1)
	    ans = 2*ans + R[i];
	  else {
	    ans = 2*ans + 1;
	    count++;
	  }

	  if(!flag)
	    flag1 = false;
	  
	  if(R[i] == 1 && flag1)
	    count++;
	  //trace1(count);
	}
	
	//trace2(set2, count);
	
	if(set2 > count) {
	  //cout<<"hello"<<endl;
	  ans = re;
	  //cout<<ans<<endl;
	}
      }
    }
    
    else 
      ans = f1(len2-1);
    
    cout<<ans<<endl;
  }

  return 0;
}
