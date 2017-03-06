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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

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

struct compare  
{  
  bool operator()(const int& l, const int& r)  
  {  
    return l > r;  
  }  
};

vector<priority_queue<pair <int,string> > > v;

int main() {

  priority_queue<int, string> temp;
  
  int n, m, i, x, y;
  string str;
  
  cin>>n>>m;

  v.resize(m+1);
  
  rep(i, 1, n+1) {
    
    cin>>str>>x>>y;

    if(v[x].size() < 2)
      v[x].push(mp(-y, str));
    else if(y == -v[x].top().first) {
      v[x].push(mp(-y, str));
    }
    
    else if(y > -v[x].top().first) {
      while(y > -v[x].top().first) { 
	temp.pb(v[x].top);
	v[x].pop();
      }

      while(!temp.empty()) {
	temp.pop()
      v[x].push(mp(-y, str));
    }
    
  }

  string str1, str2;
  
  rep(i, 1, m+1) {
    if(v[i].size() > 2)
      cout<<"?"<<endl;
    else {
      str1 = v[i].top().second;
      v[i].pop();
      str2 = v[i].top().second;
      cout<<str2<<" "<<str1<<endl;
    }
  }
  
  return 0;
}
