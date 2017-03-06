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

LL a[N], val[N];

int main() {

  ios::sync_with_stdio(false);  
  cin.tie(NULL);

  LL n, k;
  cin >> n >> k;

  map<LL, LL> m;
  m[0] = 1;

  LL upper = log2(1e14+2);

  val[0] = 1;

  for(int i = 1; i <=  upper + 3; i++) {
    val[i] = val[i-1]*k;
  }

  LL s = 0, ans = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
    //trace(i, s);
    if(abs(k) != 1) {
      for(int j = 0; j <= upper+3; j++) {
        if(val[j] == 0) continue;
        if(m.find(s-val[j]) != m.end()) {
          ans += m[s-val[j]];
          //trace(s, s - val[j], ans);
        }
      }
    }
    else {
      if(k == 1) {
        if(m.find(s-val[0]) != m.end()) {
            ans += m[s-val[0]];
          }
        }
      else {
        if(m.find(s-val[0]) != m.end()) {
            ans += m[s-val[0]];
          }
        if(m.find(s+val[0]) != m.end()) {
            ans += m[s+val[0]];
          }
        }
      }
    m[s]++;
  }  

  cout << ans << endl;
  return 0;
}