#include<iostream>
#include<stdio.h>
#include<stack>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

#define LL long long int
#define rep(i, a, b) for(i = a; i < b; i++)

vector<vector<int> > g;
vector<vector<int> > gr;
vector<set<int> > scc(6);
stack<int>s;
int cnt, flag[1000], flag1[1000], in[1000], out[1000];
int n;

LL lcm(LL a, LL b) {
  return (a*b)/__gcd(a, b);
}

void dfs(int v)
{
  flag[v] = 1;
  
  for(vector<int>::iterator it = g[v].begin(); it != g[v].end(); it++)
    if(flag[*it] == 0)
      {
	flag[*it] = 1;
	dfs(*it);
      }
  
  s.push(v);
  return; 
}

void rev_adjlist(int n) {
  for(int i = 1; i <= n; i++)
    for(vector<int>::iterator it = g[i].begin(); it != g[i].end(); it++)
      gr[*it].push_back(i);  
  return;
}

void dfsr(int v)
{
  flag1[v] = 1;
  cnt++;
  
  for(vector<int>::iterator it = gr[v].begin(); it != gr[v].end(); it++)
    if(flag1[*it] == 0)
      dfsr(*it);
  
  return; 
}

void add_edge(int u, int v)
{
  g[u].push_back(v);
  return;
}

int main()
{
  cin>>n;

  int i;

  g.resize(n+1);
  gr.resize(n+1);

  rep(i, 1, n+1) {
    int x;
    cin>>x;
    add_edge(i, x);
    out[i]++;
    in[x]++;
  }

  bool fllag = true;
  
  rep(i, 1, n+1)
    if(in[i] != 1 || out[i] != 1)
      fllag = false;

  rep(i, 1, n+1)
    if(flag[i] == 0)
      dfs(i);
  
  rev_adjlist(n);

  LL ans = 1;

  if(fllag == false) { 
    cout<<"-1"<<endl;
    return 0;
  }
  
  while(!s.empty())
    {
      if(flag1[s.top()] == 0)
	{
	  cnt = 0;
	  dfsr(s.top());
	  if(cnt % 2 == 1)
	    ans = (LL)lcm(ans, cnt);
	  else
	    ans = (LL)lcm(ans, cnt/2);
	}
      s.pop();
    }

  cout<<ans<<endl;
  
  return 0;
}
