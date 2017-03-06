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

set<pair<queue<int>, queue<int> > > s;
queue<int> q1, q2;
int main() {
  ios::sync_with_stdio(false);	cin.tie(NULL);
  int n,x ; cin>>n;
  int k1; cin>>k1; while(k1--) { cin>>x; q1.push(x); }
  int k2; cin>>k2; while(k2--) { cin>>x; q2.push(x); }
  int fights = 0, winner = 1;
  while(((int)q1.size()!=0)&&((int)q2.size()!=0))
    {
      fights++;
      s.insert({q1, q2});
      int t1 = q1.front(), t2 = q2.front();
      q1.pop(); q2.pop();
      if(t1 > t2)
	{
	  q1.push(t2);
	  q1.push(t1);
	}
      else
	{
	  q2.push(t1);
	  q2.push(t2);
	}
      if(s.find({q1, q2}) != s.end())
	{
	  cout<<-1<<endl;
	  return 0;
	}
    }

  if((int)q1.size() == 0)
    winner = 2;
  else
    winner = 1;
  cout<<fights<<" "<<winner<<endl;
  return 0;
}
