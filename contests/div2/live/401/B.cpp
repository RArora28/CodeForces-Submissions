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

const int N = 1e5+10;
const int mod = 1e9+7;

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int n;
  cin >> n;
  string sher, mor;
  cin >> sher >> mor;

  map<int, int> m, m1;
  for(auto mo : mor) {
  	m[mo-'0']++;
  	m1[mo-'0']++;
  } 

  int max_fl = 0;

  for(auto sh: sher) {
  	bool flag1 = false;
  	for(int i = sh-'0'+1; i <= 9; i++) {
  		if(m[i]) {
  			m[i]--;
  			max_fl++;
  			flag1 = true;
  			break;
  		}
  	}
  	if(!flag1) {
  		for(int i = 0; i <= sh-'0'; i++) {
  			if(m[i]) {
  				m[i]--;
 				break;
  			}		
  		}
  	}
  }

  int min_fl = n;

  for(auto sh: sher) {
  	bool flag1 = false;
  	for(int i = sh-'0'; i <= 9; i++) {
  		if(m1[i]) {
  			m1[i]--;
  			min_fl--;
  			flag1 = true;
  			break;
  		}
  	}
  	if(!flag1) {
  		for(int i = 0; i < sh-'0'; i++) {
  			if(m1[i]) {
  				m1[i]--;
 				break;
  			}		
  		}
  	}
  }


  cout << min_fl << endl;
  cout << max_fl << endl;


  return 0;
}
