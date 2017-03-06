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

int a[N], c[N], b[N];
II p[N];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int n, l, r;
  cin >> n >> l >> r;
  for(int i = 1; i <= n; i++) {
  	cin >> a[i];
  }

  for(int i = 1; i <= n; i++) {
  	cin >> p[i].F;
  	p[i].S = i;
  }

  sort(p + 1, p + n + 1);

  b[p[1].S] = l;
  c[p[1].S] = l - a[p[1].S];
  int prev = c[p[1].S];

  for(int i = 2; i <= n; i++) {
    b[p[i].S] = max(l, a[p[i].S] + prev + 1);
    prev = b[p[i].S] - a[p[i].S];
  }

  for(int i = 1; i <= n; i++) {
    if(b[i] > r) {
      cout << -1 << endl;
      return 0;
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << b[i] << ' ';
  }

  cout << endl;
  return 0;
}
