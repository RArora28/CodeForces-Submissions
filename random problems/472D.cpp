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

const int N = 1e5;
const int mod = 1e9+7;

LL n;
LL d[2500][2500];
map< pair<LL, LL>, LL> S;

bool rec(LL a, LL b)
{
  if(S.find(MP(a, b)) != S.end())
    return true;
  else
    S.insert(MP(a, b));
  
  if(a == b)
    return (d[a][a] == 0);
  else if(d[a][b] != d[b][a] || d[a][b] == 0)
    return false;
  LL i;
  
  rep(i, 1, n+1)
    if(d[a][i] + d[i][b] == d[a][b])
      return (rec(a, i) & rec(b, i));
  return false;
}
int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  LL i, j;
  
  cin>>n;

  rep(i, 1, n+1)
    rep(j, 1, n+1)
    cin>>d[i][j];

  bool ans = true;

  rep(i, 1, n+1)
    ans &= rec(1, i);

  ans == true ? puts("YES")  : puts("NO");
  
  return 0;
}
