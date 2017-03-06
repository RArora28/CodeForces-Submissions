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

#define j 200010
int A[j], tree[4*j];

int build(int low, int high, int pos) {   
  if(low == high) {
    tree[pos] = A[low];
    return 1;
  }
  
  int mid = (low + high) >> 1;
  int x;
  x = build(low, mid, 2*pos);
  x = build(mid + 1, high, 2*pos + 1);

  if( x == 1)
    tree[pos] = tree[2*pos] | tree[2*pos + 1];
  else 
    tree[pos] = tree[2*pos] ^ tree[2*pos + 1];
  
  return (1-x);
}

int update(int low, int high, int pos, int r) {
  
  if(high < r || low > r)
    return -1;
  
  else if(low ==  high) {
    tree[pos] = A[r];
    return 1;
  }
   
  int mid = (low + high) >> 1;
  
  int x ,y , z;
  y = update(low, mid, 2*pos, r);  
  z = update(mid + 1, high, 2*pos + 1, r);
  
  if(y != -1)
    x = y;
  else 
    x = z;
  
  if( x == 1)
    tree[pos] = tree[2*pos] | tree[2*pos + 1];
  else 
    tree[pos] = tree[2*pos] ^ tree[2*pos + 1];
  
  return (1-x);
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int n, m;
  int i;

  cin>>n>>m;

  int k = 1 << n;
  
  rep(i, 1, k+1)
    cin>> A[i];
  
  build(1, k, 1);
  
  int a, b;
  
  while(m--) {
    cin>>a>>b;
    A[a] = b;
    update(1, k, 1, a);
    cout<<tree[1]<<endl;
  }
  
  return 0;
}
