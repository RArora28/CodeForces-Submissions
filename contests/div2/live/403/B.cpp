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

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  double n;
  cin >> n;
  pair<double, double> p[(int)n+10];

  for(int i = 1; i <= (int)n; i++) {
  	cin >> p[i].F;
  }

  for(int i = 1; i <= (int)n; i++) {
  	cin >> p[i].S;
  }

  sort(p + 1, p + (int)n + 1);

  double ans1 = -1;

  for(int i = 1; i <= n-1; i++) {
  ans1 = max(ans1, (double) (p[(int)n].F - p[i].F) / (p[(int)n].S + p[i].S));
	}

  double ans2 = -1;

  for(int i = 2; i <= n; i++) {
  ans2 = max(ans2, (double) (p[(int)i].F - p[1].F) / (p[(int)i].S + p[1].S));
	}

	cout << setprecision(7) << min(ans1, ans2);
  return 0;
}
