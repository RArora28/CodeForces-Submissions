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

int child[500005],l[500005],depth[500005],cnt[26][500005],st[500005],ft[500005],timer,ver[500005];
int ans[500005];
vector<vi> v;
vector<vii> quer;
int dfs1(int u,int par)
{
  int i;
  if(u==1)
    depth[u]=1;
  child[u]=1;
  st[u]=timer;
  ver[timer]=u;
  timer++;
  rep(i,0,v[u].size())
    {
      int v1=v[u][i];
      if(v1!=par)
	{
	  depth[v1]=depth[u]+1;
	  dfs1(v1,u);
	  child[u]+=child[v1];
	}
    }
  ft[u]=timer;
}
void dfs(int u,int par,bool keep)
{
  int j,i,mx=0,bigchild=-1;
  rep(i,0,v[u].size())
    {
      int v1=v[u][i];
      if(v1!=par && child[v1]>mx)
	mx=child[v1],bigchild=v1;
    }
  rep(i,0,v[u].size())
    {
      int v1=v[u][i];
      if(v1!=par && v1!=bigchild)
        dfs(v1,u,0);
    }
  if(bigchild!=-1)
    dfs(bigchild,u,1);
  rep(i,0,v[u].size())
    {
      int v1=v[u][i];
      if(v1!=par && v1!=bigchild)
	{
	  rep(j,st[v1],ft[v1])
	    {
	      int v2=ver[j];
	      cnt[l[v2]][depth[v2]]++;
	    }
	}
    }
  cnt[l[u]][depth[u]]++;
  rep(i,0,quer[u].size())
    {
      int ind=quer[u][i].se,cn1=0,h1=quer[u][i].fi;
      rep(j,0,26)
	if(cnt[j][h1]%2!=0)
	  cn1++;
      if(cn1<=1)
	ans[ind]=1;
      else
	ans[ind]=0;
    }
  if(!keep)
    {
      rep(j,st[u],ft[u])
	cnt[l[ver[j]]][depth[ver[j]]]--;
    }
}
int main()
{
  int x,y,n,m,i,j,k;
  si(n); si(m); v.resize(n+2);
  quer.resize(n+2);
  rep(i,2,n+1)
    {
      si(x);
      v[x].PB(i); v[i].PB(x);
    }
  string s;
  cin>>s;
  rep(i,1,n+1)
    l[i]=(int)(s[i-1]-'a');
  dfs1(1,-1);
  rep(i,1,m+1)
    {
      si(x); si(y);
      quer[x].PB(MP(y,i));
    }
  dfs(1,-1,1);
  rep(i,1,m+1)
    if(ans[i])
      printf("Yes\n");
    else
      printf("No\n");
  return 0;
}
