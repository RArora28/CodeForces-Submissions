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

const int N = 2e5+10;
const int mod = 1e9+7;

int a[N], b[N];
II d[N];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];
  
  int c = 0, s1 = 0, s2 = 0;

  for(int i = 1; i <= n; i++) {
  	if(a[i] < b[i]) {
  		c++;
  		s1 += a[i];
  	}
  	else {
  		s2 += b[i];
  	}
  }

  if(c >= k) {
  	cout << s1 + s2 << '\n';
  	return 0;
  }

  for(int i = 1; i <= n; i++) {
  	d[i].F = a[i]-b[i];
  	d[i].S = i;
  }

  sort(d+1, d+n+1);

  c = 0, s1 = 0, s2 = 0;

  int i = 1;

  while(c < k) {
  	s1 += a[d[i].S];
  	i++;
  	c++;
  } 

  while(c < n) {
  	s2 += b[d[i].S];
  	i++;
  	c++;
  }

  cout << s1 + s2 << '\n';
  return 0;
}
