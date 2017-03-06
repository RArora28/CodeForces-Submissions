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

int a[100010], b[100010];

int main() {

  int n, m, i, j, x, start, end;

  cin>>n;

  rep(i, 0, n) {
    cin>>a[i];
    b[i] = a[i];
  }

  sort(b, b+n);
  
  bool flag = false, flag2 = false;;
  
  rep(i, 0, n-1) {
    if(a[i] > a[i+1] && !flag) {
      flag = true;
      start = i;
    }
    
    else if(a[i] < a[i+1] && flag == true) {
      end = i;
      flag2 = true;
      break;
    }
  }

  if(!flag2 && flag)
    end = n-1;
  
  int s = start;
  int e = end;
  
  while(start < end) {
    swap(a[start], a[end]);
    start++;
    end--;   
  }

  bool flag1 = false;
  
  rep(i, 0, n) {
    //    cout<<a[i]<<endl;
    if(a[i] != b[i])
      flag1 = true;
  }
  
  if(flag1)
    cout<<"no"<<endl;
  else if(!flag)
    cout<<"yes"<<endl<<"1 1"<<endl;
  else 
    cout<<"yes"<<endl<<s+1<<" "<<e+1<<endl;

  return 0;
}

