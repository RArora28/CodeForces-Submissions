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

struct node {
  int first, second, ans;
};

ll sum = 0;
vector< vector < node > > adj;
int c[1000010], arr[200010], i, n;
ll query[200010];

void add(int ind) {
  if(ind == 0 || ind == n+1)
    return;

  int temp = arr[ind];
  sum += (ll)(2*c[temp] + 1) * (ll)temp;
  ++c[temp];
  return;
}

void remove(int ind) {
  if(ind == 0 || ind == n+1)
    return;
  int temp = arr[ind];
  sum -= (ll)(2*c[temp] - 1) * (ll)temp;
  --c[temp];
  return;
}

bool compare(node A, node B) {
  return (A.second < B.second); 
}

int main() { 

  int t;

  cin>>n>>t;
  
  int maximum = -1;

  rep(i, 1, n+1) {
    cin>>arr[i];
    maximum = max(maximum, arr[i]);
  }
  
  int temp = sqrt(n);
  int T = t;

  adj.resize((n/temp)+2);

  rep(i, 1, T+1) {
    int l, r;
    
    cin>>l>>r;
    
    node tem;
    tem.first = l;
    tem.second = r;
    tem.ans = i;
    
    if(l % temp == 0) 
      adj[l/temp].pb(tem);
    else 
      adj[(l/temp)+1].pb(tem);
    //cout<<"hello"<<endl;
  }
  
  rep(i, 1, (n/temp) + 2)
    sort(adj[i].begin(), adj[i].end(), compare); //add comparator for second element sort
  
  // rep(i, 1, ntemp + 2) {
  //   cout<<i<<endl;
    
  //   for(auto it : adj[i]) 
  //     cout<<it.first<<" "<<it.second<<endl;
  // }

  rep(i, 1, (n/temp) + 2) {
    
    memset(c, 0, sizeof(c));
    sum = 0;
    int L, R;
    int start = (i-1)*temp;
    int end = start;
    //cout<<i<<" "<<start<<" "<<end<<endl;
    for(auto it : adj[i]) {
      L = it.first;
      R = it.second;
     
      while(end <= R) {
	add(end);
	end++;
      }
      
      while(start > L) {
	add(start-1);
	start--;
      }
      
      while(start < L) {
	remove(start);
	start++;
      }
      
      // rep(i, 1, 4) {
      // 	cout<<c[i]<<" ";
      // }
      
      // cout<<endl;

      //    cout<<sum<<endl;
      //cout<<sum<<endl;
      query[it.ans] = sum;
    }
  }
  
  rep(i, 1, T+1)
    cout<<query[i]<<endl;
  
  return 0;
}

