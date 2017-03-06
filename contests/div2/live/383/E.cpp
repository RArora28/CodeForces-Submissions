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

vector<VI> adj;
int a[2*MAXSIZE], b[2*MAXSIZE], color[2*MAXSIZE];
bool vis[2*MAXSIZE],ok = true;

void dfs(int v, int c)
{
  vis[v] = true;
  color[v] = c;

  for(auto it : adj[v])
    {
      if(vis[it])
	{
	  if(color[it] == color[v])
	    {
	      ok = false;
	      return;
	    }
	}
      else
	dfs(it, 1-c);
    }
  return;
}
							  
int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n;
  int i;
  cin>>n;

  adj.resize(2*n+1);

  int N = 2*n;
  
  rep(i, 1, n+1)
    {
      cin>>a[i]>>b[i];
      adj[a[i]].PB(b[i]);
      adj[b[i]].PB(a[i]);
    }

  rep(i, 1, n+1)
    {
      adj[2*i].PB( (2*i)%N +1);
      adj[(2*i)%N +1].PB(2*i);      
    }
  rep(i, 1, 2*n+1)
      if(!vis[i])
	  dfs(i, 1);

  if(!ok)
    cout<<-1<<endl;
  else
      rep(i, 1, n+1)
	cout<<color[a[i]]+1<<" "<<color[b[i]]+1<<endl;
  
  return 0;
}
