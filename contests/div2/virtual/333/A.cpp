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

LL calc(vector<LL> dig, LL base) {
	LL ans = 0;
	for(int i = 0; i < (int)dig.size(); i++) {
		ans = base*ans + dig[i];
	}
	return ans;
}
int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  vector<LL> digX, digY;
  LL n, baseX, baseY;

  cin >> n >> baseX;
  digX.resize(n);
  for(int i = 0; i < n; i++) {
  	cin >> digX[i];
  }
	
  cin >> n >> baseY;
  digY.resize(n);
  for(int i = 0; i < n; i++) {
  	cin >> digY[i];
  }

  LL ansX = calc(digX, baseX);
  LL ansY = calc(digY, baseY);

  trace(ansX, ansY);
  if(ansX < ansY) {
  	cout << '<' << endl;
  }
  else if(ansX > ansY) {
  	cout << '>' << endl;
  }
  else  {
  	cout << '=' << endl;
  }
  return 0;
}
