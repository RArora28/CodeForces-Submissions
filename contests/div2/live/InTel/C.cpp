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

set<LL> I;
map<LL, LL> M;

LL a[MAXSIZE], p[MAXSIZE], r[MAXSIZE];
LL L, R;

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  LL n;
  cin>>n;

  LL i;
  rep(i, 1, n+1) 
    cin>>a[i];
  
  r[0] = 0;
  r[1] = a[1];
  
  rep(i, 2, n+1)
    r[i] = r[i-1] + a[i];
  
  M[r[n]] = 1;
 
  rep(i, 1, n+1) {
    cin>>p[i]; 
    I.insert(p[i]);
    set<LL>::iterator it = I.find(p[i]);
    
    if(it == I.begin())
      L = 0;
    else {
      it--;
      L = *it;
      it++;
    }
    
    set<LL>::iterator itr = I.end();
    itr--;
    
    if(it == itr)
      R = n+1;
    else {
      it++;
      R = *it;
      it--;
    }
    
    //trace(L, R);
    M[r[R-1]-r[L]]--;
    if(M[r[R-1]-r[L]] == 0)
      M.erase(r[R-1]-r[L]);
    
    if(M.find(r[R-1] - r[p[i]]) != M.end())
      M[r[R-1] - r[p[i]]]++;
    else 
      M[r[R-1] - r[p[i]]] = 1;
    
    if(M.find(r[p[i]-1] - r[L]) != M.end())
      M[r[p[i]-1] - r[L]]++;
    else 
      M[r[p[i]-1] - r[L]] = 1;

    map<LL, LL>::iterator itr1 = M.end();
    itr1--;
    cout<<(*itr1).F<<endl;
  }

 
  
  return 0;
}
