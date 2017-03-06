/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int,long long int> II;
typedef vector<long long int> VI;
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

const long long int N = 2e5+10;
LL A1[N], ans, p[N], sub[N], ch[N];
vector<VI> adj;
bool vis[N];

void dfs(int v)
{
  vis[v] = true;
  sub[v] = p[v];
  ch[v] = 0;
  for(auto it : adj[v])
    {
      if( !vis[it] )
	{
	  dfs(it);
	  ch[v]++;
	  sub[v] += sub[it];
	}
    }
  
  return;
}

void dfs2(int v) 
{
  vis[v] = true;
  LL max1 = LLONG_MIN;
  LL max2 = max1;
  
  if(ch[v] == 0)
    {
      //trace(v, A1[v]);
      A1[v] = sub[v];
      return;
    }
  
  for(auto it : adj[v])
    {
      if( !vis[it] )
	{
	  dfs2(it);

	  if(ch[v] == 1)
	    {
	      A1[v] = max(A1[it], sub[v]);
	    }
	  else
	    {
	      if(A1[it] > max1)
		{
		  max2 = max1;
		  max1 = A1[it];
		}
	      else if(A1[it] > max2)
		max2 = A1[it];
	    }
	}
    }
  
  if(ch[v] >= 2)
    {
      A1[v] = max(max1, sub[v]);
      //trace(v, max1, max2, ans);
      ans = max(ans, max1 + max2);
    }
  
  //trace(v, A1[v]);
  return;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  LL n;

  cin>>n;
  adj.resize(n+1);
  LL i;

  rep(i, 1, n+1) {
    cin>>p[i];
    A1[i] = LLONG_MIN;
  }

  ans = LLONG_MIN;
  
  LL a, b;
  
  rep(i, 1, n)
    {
      cin>>a>>b;
      adj[a].PB(b);
      adj[b].PB(a);
    }

  dfs(1);
  SET(vis, false);
  dfs2(1);

  //rep(i, 1, n+1)
  //trace(i, ch[i], sub[i], A1[i]);
  
  bool ok = false;

  rep(i, 1, n+1)
    if(ch[i] > 1)
      ok = true;

  if(!ok)
    cout<<"Impossible"<<endl;
  else 
    cout<<ans<<endl;
  
  return 0;
}
