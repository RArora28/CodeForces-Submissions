/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 100005
#define mod 1000000007
#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)
#define INF INT_MAX
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))

//debugging statements
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

map<char, LL> m1, m2;
LL dp[100][20][10];
bool A[100][20][10];
LL arr[100][2];

bool f(LL i, LL arr[][2]) { 
  
  if(i == 1) 
    return true;
  
  else if(dp[i][arr[i][0]][arr[i][1]] != -1)
    return A[i][arr[i][0]][arr[i][1]];
  
  bool temp = false;
  
  if(i > 1)
    if( (arr[i][0] == arr[i-1][0])  ||  (arr[i][1] == arr[i-1][1]) ) {
      LL temp1 = arr[i-1][0], temp2 = arr[i-1][1];
      arr[i-1][0] = arr[i][0], arr[i-1][1] = arr[i][1];
      temp |= f(i-1, arr);
      arr[i-1][0] = temp1, arr[i-1][1] = temp2;
    }
  
  if(i > 3) 
    if( (arr[i][0] == arr[i-3][0])  ||  (arr[i][1] == arr[i-3][1]) ) {
      LL temp1 = arr[i-3][0], temp2 = arr[i-3][1];
      arr[i-3][0] = arr[i][0], arr[i-3][1] = arr[i][1];
      temp |= f(i-1, arr);
      arr[i-3][0] = temp1, arr[i-3][1] = temp2;
    }
  
  dp[i][arr[i][0]][arr[i][1]] = 1;
  return A[i][arr[i][0]][arr[i][1]] = temp;
}

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  SET(dp, -1);
  
  m1['A'] = 1;
  m1['2'] = 2;
  m1['3'] = 3;
  m1['4'] = 4;
  m1['5'] = 5;
  m1['6'] = 6;
  m1['7'] = 7;
  m1['8'] = 8;
  m1['9'] = 9;
  m1['T'] = 10;
  m1['J'] = 11;
  m1['Q'] = 12;
  m1['K'] = 13;
  
  m2['S'] = 1;
  m2['D'] = 2; 
  m2['H'] = 3; 
  m2['C'] = 4;
  
  LL n;
  LL i;
  
  cin>>n;
  
  rep(i, 1, n+1) {
    
    char str[2];
    cin>>str;
    arr[i][0] = m1[str[0]];
    arr[i][1] = m2[str[1]];
    //trace(i, str, m2[str[1]], arr[i][0], arr[i][1]);
  }
  
  // rep(i, 1, n+1)
  //   trace(i, arr[i][0], arr[i][1]);

  bool ok = f(n, arr);

  if(ok)
    cout<<"YES"<<endl;
  else 
    cout<<"NO"<<endl;

  return 0;
}
