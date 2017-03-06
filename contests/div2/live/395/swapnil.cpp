#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> pii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pii> vpii;
typedef long long int ll;
typedef unsigned long long int ull;

#define mi 1000000007
#define rep(i,a,b) for(i=a;i<b;i++)
#define repv(i,a,b) for(i=b-1;i>=a;i--)
#define pr(arr,n) rep(i,0,n) cout<<arr[i]<<" "; cout<<endl;
#define pr1(arr,n) rep(i,1,n+1) cout<<arr[i]<<" "; cout<<endl;
#define inf INT_MAX
#define gc getchar_unlocked
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define SET(a,b) memset(a,b,sizeof(a))
#define MAX 500005
#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

int mult(int x,int y)
{
  ll ans,x1=(ll)x,y1=(ll)y;
  ans=(x1*y1)%mi;
  return (int)ans;
}
int gcd(int a,int b) { return b==0 ? a : gcd (b,a%b);}
int lcm(int a,int b) { return a*(b/gcd(a,b));}

ll pow1(ll a,ll b)
{
  ll ans=1;
  while(b>0)
    {
      if(b&1) ans=(ans*a)%mi;	
      a=(a*a)%mi; b>>=1;
    }	
  return ans;
}
int mina(int arr[],int n)
{
  int x=arr[0],i,pos=0;
  rep(i,1,n){ if(arr[i]<x) { x=arr[i]; pos=i; } }
  return x;
}
int maxa(int arr[],int n)
{
  int x=arr[0],i,pos=0;
  rep(i,1,n){ if(arr[i]>x) { x=arr[i]; pos=i; } }
  return x;
}
bool ans;
int c[100005];
int root=1;
vector<vi> v;
int dfs0(int u, int p)
{
  int i;
  rep(i,0,v[u].size())
    {
      int v1=v[u][i];
      if(v1!=p)
	{
	  int x=dfs0(v1,u);
	  if(x != c[u] && !ans)
	    {
	      ans=true;
	      root=u;
	    }
	}
    }
  return c[u];
}
bool ok = true;
void dfs1(int u,int p,int val)
{
  if(c[u]!=val)
    ok=false;
  int i;
  rep(i,0,v[u].size())
    {
      int v1=v[u][i];
      if(v1!=p)
	dfs1(v1,u,val);
    }
  return;
}
int main()
{
  int n,a,b,i,j; 
  si(n); v.resize(n+2);
  rep(i,1,n)
    {
      si(a); si(b);
      v[a].PB(b); v[b].PB(a);
    }
  rep(i,1,n+1)
    si(c[i]);
  dfs0(1,-1);
  rep(i,0,v[root].size())
    dfs1(v[root][i],root,c[v[root][i]]);
  if(ok)
    cout<<"YES"<<'\n'<<root<<'\n';
  else
    cout<<"NO"<<endl;
  return 0;
}

