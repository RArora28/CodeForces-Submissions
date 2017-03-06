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
#define rev(i, a, b) for(i = a; i > b; i--)
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

map<string, LL> S;
map<LL, LL> M;

string gen(string str) {
  
  reverse(str.begin(), str.end());
  
  while(str.size() != 18)
    str += '0';
  
  reverse(str.begin(), str.end());

  return str;
}

string give(LL x) { 

  string str1;
  LL i;

  while(x != 0) {
    i = x%10;
    //cout<<i<<endl;
    if(i % 2 == 1)
      str1 += '1';
    else 
      str1 += '0';
    //cout<<str1<<endl;
    x /= 10;
  }
  
  while(str1.size() != 18)
    str1 += '0';
  
  reverse(str1.begin(), str1.end());

  //cout<<str1<<endl;
  return str1;
}

int main() {

  LL t, x;
  char ch;
  string Y;

  cin>>t;

  while(t--) { 
    cin>> ch;

    if(ch == '+') {
      cin>>x;
      
      if(M.find(x) != M.end()) { 
	M[x]++; 
      }
      else  {
	M[x] = 1;
      }

      if(S.find(give(x)) != S.end()) { 
	S[give(x)]++; 
      }
      else  {
	S[give(x)] = 1;
      }

      //cout<<give(x)<<endl;
    }
    
    else if(ch == '-') {
      cin>>x;
      M[x]--;
      S[give(x)]--;
    }
    
    else {
      cin>>Y;
      Y = gen(Y);
      //cout<<Y<<endl;
      cout<<S[Y]<<endl;
    }

  }

  return 0;
}
