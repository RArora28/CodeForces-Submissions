/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

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

const int N = 1e5+10;
const int mod = 1e9+7;

LL dp1[1100][1100], dp2[1100][1100];
string s;
LL n, a[30];
LL Max = 1;

LL f1 (LL i, LL len) {
	for(LL j = i-len; j <= i; j++) {
		if(a[s[j]-'a'] < len+1) {
			return dp1[i][len] = 0;
		}
	}
	Max = max(Max, len+1);
	if( i == n-1) {
		return 1;
	}

	else if(dp1[i][len] != -1) {
		return dp1[i][len];
	}

	dp1[i][len] = f1(i+1, 0);
	dp1[i][len] = (dp1[i][len] % mod + f1(i+1, len+1) % mod) % mod;
	return dp1[i][len] % mod;
}

LL f2 (LL i, LL len) {
	for(int j = i-len; j <= i; j++) {
		if(a[s[j]-'a'] < len+1) {
			return dp2[i][len] = INT_MAX;
		}
	}
	if( i == n-1) {
		return 1;
	}
	else if(dp2[i][len] != -1) {
		return dp2[i][len];
	}
	dp2[i][len] = 1 + f2(i+1, 0);
	dp2[i][len] = min(dp2[i][len], f2(i+1, len+1));
	return dp2[i][len];
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
 
  cin >> n; cin >> s;

  for(int i = 0; i < n+10; i++) {
  	for(int j = 0; j < n + 10; j++) {
  		dp1[i][j] = -1;
  		dp2[i][j] = -1;
   	}
  }

  for(int i = 0; i < 26; i++) {
  	cin >> a[i];
  }


  cout << f1(0, 0) << endl;
  cout << Max << endl;
  cout << f2(0, 0) << endl;
  return 0;
}