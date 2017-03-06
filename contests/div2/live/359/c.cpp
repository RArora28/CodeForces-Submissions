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

ll Ans = 0;
int n, m, i;
int nc = 0, nmax, mc= 0, mmax;

void bitmask(int i, int arr[]) {

  if(i == nc + mc + 1) {

    bool flag = true;
    int t[10], j;
    
    rep(j, 0, 10)
      t[j] = 0;

    
    rep(j, 1, i) {
      //cout<<arr[j]<<" ";
      t[arr[j]]++;
      //cout<<t[arr[j]]<<endl;
    }

    int N = 0;
    int M = 0;
    int p = nc-1;
    
    rep(j, 1, nc+1) {
      N += arr[j]*pow(7, p);
      p--;
    }
    
    p = mc-1;

    rep(j, nc + 1, i) {
      M += arr[j]*pow(7, p);
      p--;
    }

    
    if(N > (n-1) || M > (m-1))
      flag = false;

    rep(j, 0, 10) {
      //cout<<t[j]<<" ";
      if(t[j] >= 2) {
	flag = false;
	break;
      }
    }

    if(flag == true)  {
      //    cout<<N<<M<<endl;
      Ans++;
    }
    
    return;
  }

  int j;
  
  rep(j, 0, 7) {
    arr[i] = j;
    bitmask(i+1, arr);
  }
  
  return;
}


int main() {

  int arr[100];
  
  cin>>n>>m;

  int ntemp = n-1, mtemp = m-1;

  if(ntemp == 0)
    nc = 1;
  if(mtemp == 0)
    mc = 1;
  
  while(ntemp > 0) {
    nc++;
    ntemp /= 7;
  }
  
  while(mtemp > 0) {
    mc++;
    mtemp /= 7;
    
  }

  if((nc + mc) > 7)
    cout<<"0"<<endl;

  else {
    bitmask(1, arr);
    cout<<Ans<<endl;
  }
  
  return 0;
}

