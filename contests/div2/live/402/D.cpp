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

const int N = 2e5+10;
const int mod = 1e9+7;

int a[N], vis[N];

bool isSubSequence(string a, string b) {
   int n = a.size();
   int m = b.size();
   int j = 0;
   if(n < m)
   	return false;
   for (int i = 0; i < n && j < m; i++)
       if (b[j] == a[i])
         j++;
   return (j == m);
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  string t, p;
  cin >> t;
  cin >> p;
  int T = (int)t.size();
  for(int i = 0; i < T; i++) { 
  	cin >> a[i];
  	a[i]--;
  }

  int low = 0;
  int high = T-1;
 	int mid;
  if(!isSubSequence(t, p)) {
  	cout << 0 << '\n';
  	return 0;
  }

  bool ok;
  while(low < high) {
  	mid = (low + high + 1) / 2;
  	for(int i = 0; i <= mid; i++) {
  		vis[a[i]] = true;
  	}
  	string s;
  	for(int i = 0; i < T; i++) {
  		if(vis[i] == false) s += t[i];
  	}
  	ok = isSubSequence(s, p);
  	//trace(mid, ok, s, low, high);
  
  	if(ok) {
  		low = mid;
  	}
  	else {
  		high = mid-1;
  	}

  	for(int i = 0; i <= mid; i++) {
  		vis[a[i]] = false;
  	}
  }  	

  cout << low + 1 << endl;
  return 0;
}
