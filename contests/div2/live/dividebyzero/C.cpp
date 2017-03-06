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

int cnt1[2000], cnt2[2000];
int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  int n, k, x;
  cin >> n >> k >> x;
  int y;
  for(int i = 1; i <= n; i++) {
  	cin >> y;
  	cnt1[y]++;
  }

  for(int i = 1; i <= k; i++) {
  	int sum = 1;
  	for(int j = 0; j <= 1030; j++) {
  		if(cnt1[j]) {
  			if(sum % 2) {
  				cnt2[j] += cnt1[j]/2;
  				cnt2[j^x] += (cnt1[j]+1)/2;
  			}
  			else {
  				cnt2[j^x] += cnt1[j]/2;
  				cnt2[j] += (cnt1[j]+1)/2;
  			}
 			sum += cnt1[j];
 			sum %= 2;
  		}
  	}
  	for(int j = 0; j <= 1030; j++) {
  		cnt1[j] = cnt2[j];
  		cnt2[j] = 0;
  	}
  }

  int Max = -1, Min = 1000000;

  for(int j = 0; j <= 1030; j++) {
  	if(cnt1[j]) {
  		Max = max(j, Max);
  		Min = min(j, Min);
  	} 
  }

  cout << Max << ' ' << Min << '\n';
  return 0;
}
