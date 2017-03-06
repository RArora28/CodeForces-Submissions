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

map<int, int> m;
multiset<int> ans;

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n;
  cin >> n;
  int i;
  int x;
  rep(i, 1, n*n+1) {
  	cin >> x;
  	m[x]++;
  }

  while( (int)ans.size() < n) {
  	map<int, int>::iterator it = m.end();
  	it--;
  	int val = (*it).F;
  	m[val]--;
  	for(auto x : ans) {
  		int g = __gcd(x, val);
  		m[g] -= 2;
  		if(m[g] == 0) {
  			m.erase(g);
  		}
  	}
  	if(m[val] == 0) {
  		m.erase(val);
  	}
  	ans.insert(val);
  }

  for(auto x : ans) {
  	cout << x << ' ';
  }

  cout << endl;
  return 0;
}
