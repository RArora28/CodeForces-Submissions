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

int row[5];
int col[5];
int m[20];

int main() {

  int i, a, n;
  char str[20];

  cin>>n;
  cin>>str;
  
  int len = strlen(str);

  int temp;
  
  rep(i, 0, len) 
    m[str[i] - '0']++;

  rep(i, 0, len) { 
    temp = str[i] - '0';
    
    if(temp == 0) 
      row[4]++;
    
    else {
      if(temp % 3 == 0) {
  	row[temp/3] = 1;
  	col[3] = 1;
      }
      
      else {
  	row[temp/3+1] = 1;
  	col[temp % 3] = 1;
      }
    }
  }
 
  bool flag = false;
  
  rep(i, 1, 4)
    if(row[i] == 0 || col[i] == 0) 
      flag = true;
  
  if(m[1] > 0 && (m[9] > 0 || m[0] > 0)) 
    cout<<"YES"<<endl;
  
  else if(m[3] > 0 && (m[7] > 0 || m[0] > 0)) 
    cout<<"YES"<<endl;
 
  else if(m[2] > 0 && m[0] > 0) 
    cout<<"YES"<<endl;
  
  else if(m[1] > 0 && m[6] > 0 && (m[7] > 0 || m[9] > 0 || m[8] > 0))
    cout<<"YES"<<endl;
  
  else if(m[3] > 0 && m[4] > 0 && (m[7] > 0 || m[9] > 0 || m[8] > 0))
    cout<<"YES"<<endl;

  else if(!flag)
    cout<<"YES"<<endl;

  else 
    cout<<"NO"<<endl;

  return 0;
}

