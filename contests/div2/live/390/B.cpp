/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)
#define INF INT_MAX
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))

//debugging statements
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int N = 1e5;
const int mod = 1e9+7;

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  char ch[10][10];
  int i, j;
  
  rep(i, 1, 5)
    rep(j, 1, 5)
    cin>>ch[i][j];

  int cnt1 = 0, cnt2 = 0;

  //horizontal
  rep(i, 1, 5)
    {
      cnt1 = 0, cnt2 = 0;
      
      rep(j, 1, 4)
	{
	  if(ch[i][j] == 'x')
	    cnt1++;
	  else if(ch[i][j] == '.')
	    cnt2++;
	}
      
      if(cnt1 == 2 && cnt2 == 1)
	{
	  cout << "YES" << endl;
	  return 0;
	}
      cnt1 = 0, cnt2 = 0;
      
      rep(j, 2, 5)
	{
	  if(ch[i][j] == 'x')
	    cnt1++;
	  else if(ch[i][j] == '.')
	    cnt2++;
	}
      
      if(cnt1 == 2 && cnt2 == 1)
	{
	  cout << "YES" << endl;
	  return 0;
	}
    }

  //vertical
  rep(j, 1, 5)
    {
      int cnt1 = 0, cnt2 = 0;
      
      rep(i, 1, 4)
	{
	  if(ch[i][j] == 'x')
	    cnt1++;
	  else if(ch[i][j] == '.')
	    cnt2++;
	}
      
      if(cnt1 == 2 && cnt2 == 1)
	{
	  cout << "YES" << endl;
	  return 0;
	}
      cnt1 = 0, cnt2 = 0;
      
      rep(i, 2, 5)
	{
	  if(ch[i][j] == 'x')
	    cnt1++;
	  else if(ch[i][j] == '.')
	    cnt2++;
	}
      
      if(cnt1 == 2 && cnt2 == 1)
	{
	  cout << "YES" << endl;
	  return 0;
	}
    }
  
  //body diagnol
  cnt1 = 0, cnt2 = 0;
  
  rep(i, 1, 4)
    {
      if(ch[i][i] == 'x')
	cnt1++;
      else if(ch[i][i] == '.')
	cnt2++;
    }
  
  if(cnt1 == 2 && cnt2 == 1)
    {
      cout << "YES" << endl;
      return 0;
    }

  cnt1 = 0, cnt2 = 0;
  
  rep(i, 2, 5)
    {
      if(ch[i][i] == 'x')
	cnt1++;
      else if(ch[i][i] == '.')
	cnt2++;
    }
  
  if(cnt1 == 2 && cnt2 == 1)
    {
      cout << "YES" << endl;
      return 0;
    }

  cnt1 = 0, cnt2 = 0;
  
  rep(i, 2, 5)
    {
      if(ch[i-1][i] == 'x')
	cnt1++;
      else if(ch[i-1][i] == '.')
	cnt2++;
    }
  
  if(cnt1 == 2 && cnt2 == 1)
    {
      cout << "YES" << endl;
      return 0;
    }

  cnt1 = 0, cnt2 = 0;
  
  rep(i, 2, 5)
    {
      if(ch[i][i-1] == 'x')
	cnt1++;
      else if(ch[i][i-1] == '.')
	cnt2++;
    }
  
  if(cnt1 == 2 && cnt2 == 1)
    {
      cout << "YES" << endl;
      return 0;
    }


  //non - body
  cnt1 = 0, cnt2 = 0;
  
  rep(i, 1, 4)
    {
      if(ch[i][5-i] == 'x')
	cnt1++;
      else if(ch[i][5-i] == '.')
	cnt2++;
    }
  
  if(cnt1 == 2 && cnt2 == 1)
    {
      cout << "YES" << endl;
      return 0;
    }

  cnt1 = 0, cnt2 = 0;
  
  rep(i, 2, 5)
    {
      if(ch[5-i][i] == 'x')
	cnt1++;
      else if(ch[5-i][i] == '.')
	cnt2++;
    }
  
  if(cnt1 == 2 && cnt2 == 1)
    {
      cout << "YES" << endl;
      return 0;
    }

  cnt1 = 0, cnt2 = 0;
  
  rep(i, 1, 4)
    {
      if(ch[4-i][i] == 'x')
	cnt1++;
      else if(ch[4-i][i] == '.')
	cnt2++;
    }
  
  if(cnt1 == 2 && cnt2 == 1)
    {
      cout << "YES" << endl;
      return 0;
    }

  cnt1 = 0, cnt2 = 0;
  
  rep(i, 2, 5)
    {
      if(ch[i][4-i] == 'x')
	cnt1++;
      else if(ch[i][4-i] == '.')
	cnt2++;
    }
  
  if(cnt1 == 2 && cnt2 == 1)
    {
      cout << "YES" << endl;
      return 0;
    }


  cout << "NO" << endl;
  return 0;
}
