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

int arr[2000], brr[2000];

int main() {

  int i, n, k, a, b, c, d, fixed = 5;  

  cin>>n>>k;
  cin>>a>>b>>c>>d;
 
  if(k < n+1 || n == 4 || a == b || c == d)
    cout<<"-1"<<endl;
  
  else {
     arr[a] = arr[b] = arr[c] = arr[d] = 1;
     
    int ind = 0;
    rep(i, 1, n+1) 
      if(!arr[i])
	brr[ind++] = i;

    fixed = brr[0];
    arr[fixed] = 1;
    //first line
    cout<<a<<" ";
    
    rep(i, 1, ind)
      cout<<brr[i]<<" ";
    
    cout<<c<<" "<<fixed<<" "<<d<<" "<<b<<endl;
    
    //second line
    
    cout<<c<<" ";
    
    rev(i, ind-1, 0)
      cout<<brr[i]<<" ";
    
    cout<<a<<" "<<fixed<<" "<<b<<" "<<d<<endl;
    
  }
  
  return 0;
}

