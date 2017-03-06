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

int main() {

  ll temp, t, n, i, x, l , u, mid, count = 0;

  cin>>n>>x;

  for(i = 1; i <= n; i++) {

    temp = i;

    l = 1;
    u = n;

    while(l <= u) {
      mid = (l + u)/2;

      if(temp*mid < x)
	l = mid+1;
      else if(temp*mid > x)
	u = mid-1;
      else
	{
	  count++;
	  break;
	}
    }
  }
    cout<<count<<endl;
    
  return 0;
}

