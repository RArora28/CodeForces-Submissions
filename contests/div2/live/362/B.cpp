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

char str[1010];
int marked[10];
int main() {

  int i;
  int decimal = -1;
  int e = -1;

  cin>>str;

  int len = strlen(str);
  
  rep(i, 0, len) {
    if(e == -1)
      if(str[i] != '.' && str[i] != 'e')
	marked[str[i]-'0']++;

    if(str[i] == '.')
      decimal = i;
    else if(str[i] == 'e')
      e = i;
  }

  bool first = false;
  
  // 0 ka case
  rep(i, 1, 10)  
    if(marked[i] > 0) {
      first = true;
      break;
    }
  
  if(!first) {
    cout<<"0"<<endl;
    return 0;
  }
  
  //normal cases
  int temp = e-1;
  
  while(str[temp] == '0')
    temp--;
  
  int P = 0;
  int Power = 1;

  for(i = len-1; i > e; i--) { 
    P += (str[i]-'0')*Power;
    Power *= 10;
  }
  
  //cout<<P<<endl;

  int x;
  
  if(decimal == -1 || temp - decimal  <= P) {
    
    bool ok = false, zero = false;
    int j = 0;
    
    while(j <= temp) {
      if(ok)
	P--;
      if(str[j] == '.') {
	ok = true;
	j++;
      }
      
      else if(zero == true || str[j] != '0')
	{
	  cout<<str[j];
	  j++;
	  zero = true;
	}
      
      else 
	j++;
    }
    
    while(P > 0) { 
      cout<<"0";
      P--;
    }
  }
  
  else {
    
    //cout<<"2";
    
    bool zero = false;
    int j = 0;
    
    while(str[j] == '0' && str[j+1] == '0')
      j++;
    
    while(str[j] != '.') { 
      cout<<str[j];
      j++;
      zero = true;
    }
    
    while(P > 0) {
      if(str[j] == '.') {
	j++;
      }
      else if(zero|| str[j] != '0'){ 
	cout<<str[j];
	//cout<<"y";
	j++;
	P--;
	zero = true;
      }
      else {
	j++;
	P--;
      }
    }
    
    cout<<".";
    
    while(j <= temp) {
      if(str[j] == '.')
	j = j;
      else 
	cout<<str[j];
      j++;
    }
  }



  
  cout<<endl;

  return 0;
}
