#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define adjList vector<vector<int> >
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, z, q) for(i = z; i < q; i++)
#define rev(i, z, q) for(i = z; i > q; i--)

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll a,ll b) {
  ll ans = 1;  
  while(b > 0){
    if(b & 1)
      ans = ((ans % mod) *(a % mod)) % mod;
    a=((a % mod)*(a % mod)) % mod;
    b >>= 1;
  }
  return ans;
}

bool taken[200], flag = true;
int color[200], A[200], B[200];
adjList adj;
map<ii, int> M;

void dfs(int e) { 
  
  taken[e] = true;

  for(auto it : adj[e]) { 
    if(!taken[it]) { 
      color[it] = 1-color[e];
      dfs(it);
    }
    
    else if(color[e] == color[it]) {
      flag = false;
      return ;
    }
  }

  return;
}

bool check_neg(int i, int j) {
  
  bool ret = true;

  if(A[i] > B[i])
    swap(A[i], B[i]);

  if(A[j] >= A[i] && B[j] >= A[i] && A[j] <= B[i] && B[j] <= B[i])
      ret = false;

  if((A[j] >= B[i] || A[j] <= A[i]) && (B[j] >= B[i] || B[j] <= A[i]))
    ret = false;
  
  return ret;
}

int main() {
  
  int i, j;
  int n, m;
  
  cin>>n>>m;
  
  adj.resize(m+1);

  int a, b;

  rep(i, 1, m+1) { 
    cin>>a>>b;
    M[ii(a, b)] = i;
    M[ii(b, a)] = i;
    A[i] = a;
    B[i] = b;
  }
  
  rep(i, 1, m+1) {
    rep(j, 1, m+1) {
      if(i != j && check_neg(i, j)) 
	adj[M[ii(A[i], B[i])]].pb(M[ii(A[j], B[j])]);
    }
  }
  
  rep(i, 1, m+1)  
    if(!taken[i]) {
      color[i] = 0;
      dfs(i);
    }
  
  if(!flag) 
    cout<<"Impossible"<<endl;
  else { 
    
    rep(i, 1, m+1) { 
      if(color[i])
	cout<<"i";
      else 
	cout<<"o";
    }
    
    cout<<endl;
  }
  return 0;
}

