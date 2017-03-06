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

string s[100];
int n, m;

int check1(int x) {
	int ans = 1e7;
	for(int i = 0; i < m; i++) {
		if(s[x][i] >= 'a' && s[x][i] <= 'z') {
			ans = min(ans, i);
			break;
		}
	}
	for(int i = m-1; i >= 0; i--) {
		if(s[x][i] >= 'a' && s[x][i] <= 'z') {
			ans = min(ans, m-i);
			break;
		}	
	}
	return ans;
}

int check2(int x) {
	int ans = 1e7;
	for(int i = 0; i < m; i++) {
		if(s[x][i] -'0' >= 0 && s[x][i] - '0' <= 9) {
			ans = min(ans, i);
			break;
		}
	}
	for(int i = m-1; i >= 0; i--) {
		if(s[x][i] -'0' >= 0 && s[x][i] - '0' <= 9) {
			ans = min(ans, m-i);
			break;
		}	
	}
	return ans;
}

int check3(int x) {
	int ans = 1e7;
	for(int i = 0; i < m; i++) {
		if(s[x][i] == '#' || s[x][i] == '*' || s[x][i] == '&') {
			ans = min(ans, i);
			break;
		}
	}
	for(int i = m-1; i >= 0; i--) {
		if(s[x][i] == '#' || s[x][i] == '*' || s[x][i] == '&'){
			ans = min(ans, m-i);
			break;
		}	
	}
	return ans;	
}
int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
  	cin >> s[i];
  }

  int A = 1e7;
  for(int i = 1; i <= n; i++) {
  	for(int j = 1; j <= n; j++) {
  		for(int k = 1; k <= n; k++) {
  			if(i != j && j != k && i != k) {
  				A = min(A, check1(i) + check2(j) + check3(k)) ;
  			}	
  		}
  	}
  }

  cout << A << endl;
  return 0;
}
