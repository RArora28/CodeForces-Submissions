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

double da[100010], db[100010], dt[100010];

int main() {
  
  int i, mark1 = -1, mark2 = -1, n, x, y;
  double ax, ay, bx, by, tx, ty;
  bool flag1 = false, flag2 = false;
  double ans = 0;
  
  cin>>ax>>ay>>bx>>by>>tx>>ty;
  
  cin>>n;
  
  pair<double, int> va[n+1], vb[n+1];
  
  rep(i, 0, n) {
    cin>>x>>y;
    
    da[i] = sqrt((x-ax)*(x-ax) + (y-ay)*(y-ay));
    db[i] = sqrt((x-bx)*(x-bx) + (y-by)*(y-by));
    dt[i] = sqrt((x-tx)*(x-tx) + (y-ty)*(y-ty));
    va[i] = mp(da[i]-dt[i], i);
    vb[i] = mp(db[i]-dt[i], i);
  }
  
  sort(va, va + n);
  sort(vb, vb + n);
  
  if(va[0].se != vb[0].se) {
    if(va[0].fi <= 0) {
      mark1 = va[0].se;
      ans += da[mark1];
    }
    
    if(vb[0].fi <= 0) {
      mark2 = vb[0].se;
      ans += db[mark2];
    }
  }
  
  else if(n!=1){
    
    double temp = min(va[0].fi  + vb[1].fi, va[1].fi + vb[0].fi);

    if(temp < 0) {
      if(va[0].fi + vb[1].fi < va[1].fi + vb[0].fi && va[0].fi < 0 && vb[1].fi < 0) {
	mark1 = va[0].se;
	mark2 = vb[1].se;
      }
      else if(va[1].fi < 0 && vb[0].fi < 0){
	mark1 = va[1].se;
	mark2 = vb[0].se;
      }
      
      ans += da[mark1] + db[mark2];
    }
    
  }
  
  if(mark1 == -1 && mark2 == -1) {
    if(va[0].fi < vb[0].fi) {
      mark1 = va[0].se;
      ans += da[mark1];
    }
    
    else {
	mark2 = vb[0].se;
	ans += db[mark2];
      }
  }
  
  
  rep(i, 0, n) {
    if(i == mark1 || i == mark2)  
      ans += dt[i];
    else
      ans += 2*dt[i];
  }

  printf("%0.9lf\n", ans);
  
  return 0;
}
