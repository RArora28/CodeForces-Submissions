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

int main() { 

  ll i;
  ll arr[3];

  rep(i, 0, 3)
    cin>>arr[i];
  
  sort(arr, arr + 3);
  
  ll t = 0;
 
  ll temp = arr[2] - arr[1];
  
  if(temp % 2 == 0) {

    if(temp / 2 <= arr[0]) {
      t += temp/2;
      arr[0] -= temp/2;
    }

    else {
      t += arr[0];
      arr[0] = 0;
    }
    
    arr[2] -= temp;
  }

  else { 
    if(temp == 1) 
      temp = 1;
    else {
      temp -= 1;
      
      if(temp / 2 <= arr[0]) {
	  t += temp/2;
      arr[0] -= temp/2;
	}
	
	else {
      t += arr[0];
      arr[0] = 0;
    }
	
	arr[2] -= temp;
    
    }
  }
  
  t += (arr[0]);
  t += ((arr[1] + arr[2] - 2*arr[0]) / 3);
  
  cout<<t<<endl;

  return 0;
}

