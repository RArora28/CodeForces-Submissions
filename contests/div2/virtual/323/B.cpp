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

bool done[1200];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int n, i;
  cin >> n;
  int a[1010];
  rep(i, 1, n+1) {
  	cin >> a[i];
  }

  int val = 0;
  int j;
  int total = n;
  int ans = 0;
  bool first = true, second = false;
  i = 1;

  while(total != 0) {
  	if(first) {
  		while(i <= n) {
  			if(!done[i] && a[i] <= val) {
  				val++;
  				done[i] = true;
  				total--;
  			}
  			i++;
  		}
  		i--;
  		second = true;
  		first = false;
  	}

  	else if(second) {
  		while(i >= 1) {
  			if(!done[i] && a[i] <= val) {
  				val++;
  				done[i] = true;
  				total--;
  			}
  			i--;
  		}
  		i++;
  		first = true;
  		second = false;
  	}
  	ans++;
  }

  cout << ans -1<< endl;
  return 0;
}
