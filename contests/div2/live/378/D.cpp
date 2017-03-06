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

map<double, vector<pair<double, double> > > M;
LL a[100010], b[100010], c[100010];

double power(double A) { 
  return exp((double)log(A)/3);
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n;
  LL i;
  LL I = 1, J = 1;
  cin>>n;
  
  double ans = -1;
  
  rep(i, 1, n+1) { 
    cin>>a[i]>>b[i]>>c[i];
    M[a[i]*b[i]].PB(MP(c[i], i));
    M[c[i]*b[i]].PB(MP(a[i], i));
    M[a[i]*c[i]].PB(MP(b[i], i));
    double temp = a[i]*b[i]*c[i];
    if(temp > ans) { 
      ans = temp;
      I = i;
      J = i;
    }
  }
  
  for(auto &it : M) {  
    if( (it.S).size() >= 2 ) {
      sort((it.S).begin(), (it.S).end());
      double temp1 = it.F;
      double temp2;
      LL i = (it.S).size() - 2;
      LL val = (it.S) [(it.S).size()-1].S;
      while (i >= 0 && ((it.S)[i].S == val) )
	i--;
      if( i >= 0 ) { 
	temp2 = (it.S)[(it.S).size()-1].F + (it.S)[i].F;
	double A = temp1*temp2;
	if(A > ans) { 
	  I = (it.S)[(it.S).size()-1].S;
	  J = (it.S)[i].S;
	  ans = A;
	}
      }
    }
  }
  
  if(I == J) 
    cout<<"1"<<endl<<I<<endl;
  else { 
    if(I > J)
      swap(I, J);
    cout<<"2"<<endl<<I<<" "<<J<<endl;
  }

  return 0;
}
