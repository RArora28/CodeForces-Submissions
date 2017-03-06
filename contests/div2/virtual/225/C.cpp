/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 100005
#define mod 1000000007
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

int n, bit1[2*MAXSIZE], bit2[2*MAXSIZE], Aa[2*MAXSIZE];
VII A;

int sum(int bit[], int idx) {

  int sum = 0;

  while(idx > 0) { 
    sum += bit[idx];
    idx -= (idx & -idx);
  }
  
  return sum;
}

void update(int bit[], int idx, int val) { 
  
  while(idx <= n ) {
    bit[idx] += val;
    idx += idx & -idx;
  }

  return ;
}

bool cmp(II A, II B) { 
  return A.F > B.F;
}

int q(int bit[], int l, int r) { 
  return sum(bit, r) - sum(bit, l-1);
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int i;

  cin>>n;

  rep(i ,1, n+1) { 
    cin>>Aa[i];
    
    if(Aa[i])
      update(bit2, i, 1);
    else 
      update(bit1, i, 1);
  }
  
  int s;
  
  rep(i, 1, n+1) { 
    if(Aa[i])
      s = n-i;
    else 
      s = i-1;
    
    A.PB(MP(s, i));
  }
  
  sort(A.begin(), A.end(), cmp);
  
  LL sum = 0;

  for(auto it : A) { 
    sum += (LL)q(bit2, 1, it.S-1) + (LL)q(bit1, it.S+1, n);
    
    //trace(it.F, it.S, sum);
    if(Aa[it.S])
       update(bit2, it.S, -1);
    else 
      update(bit1, it.S, -1);
  }

  cout<<sum<<endl;
  
  return 0;
}
