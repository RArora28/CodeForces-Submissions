#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mi 1000000007

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define dout(x) printf("%d\n", x)
#define lldout(x) printf("%lld\n", x)

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define adjList vector<vector<int> >

#define ll long long int

#define pb push_back
#define mp make_pair

#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)

ll power(ll a,ll b) {

  ll ans=1;  

  while(b > 0){
      if(b & 1)
	  ans = ((ans % mi) *(a % mi)) % mi;		
      a=((a % mi)*(a % mi)) % mi;
      b >>= 1;
    }
  
  return ans;
}

ll arr[10000], temp[10000];

int main() {
  
  ll n, m, a, i, j;
  bool flag = 0;

  cin>>n>>m;

  rep(i , 0, n) {
    cin>>a;
    arr[a%m]++;
    
    if(a % m == 0)
      flag = 1;
  }
  
  for(i = 0; i < m; i++) {
    while(arr[i] != 0){
      for(j = 0; j < m; j++) 
	temp[arr[j] % m + i % m) % m]++
	if(temp[0] > 0) {
	  flag = 1;
	  break;
	}		
      }
    
      if(flag == 1)
	break;
      arr[i]--;
    }
    
    if(flag == 1)
      break;
  }
  
  if(flag == 1)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  
  return 0;
}

