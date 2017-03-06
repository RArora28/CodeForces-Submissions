/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 100005
#define mod 1000000007
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

int dp[1000][1000], pos[1000];
VI s1, s2;
int ans = 0;

int f(int i, int j)
{
  if(i < 0 || j < 0)
    return 0;
  else if(dp[i][j] != -1)
    return dp[i][j];
  else if(s1[i] == s2[j])
    return dp[i][j] = 1 + f(i-1, j-1);
  else return dp[i][j] = max(f(i-1, j), f(i, j-1) );
}

void init(int n)
{
  int i, j;
  rep(i, 0, n+1)
    {
      rep(j, 0, n+1)
	dp[i][j] = -1;
      pos[i] = 0;
    }  
  VI temp;

  rep(i, 0, (int)s1.size())
    if(pos[i] == 0)
      temp.PB(s1[i]);

  s1.resize(temp.size());
  s2.resize(temp.size());
 
  rep(i, 0, temp.size() )
    s2[i] = s1[i] = temp[i];
  
  reverse(s2.begin(), s2.end());
  return;
}

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n;
  cin>>n;
  int i;
  rep(i, 1, n+1)
    {
      int x;
      cin>>x;
      s1.PB(x);
      s2.PB(x);
    }
  
  reverse(s2.begin(), s2.end() );

  while(s1.size() > 0)
    {
      init(s1.size());
      f(s1.size()-1, s2.size()-1);
      back_track((int)s1.size());
    }

  cout<<ans<<endl;
  
  return 0;
}
