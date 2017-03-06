#include <bits/stdc++.h>

using namespace std;

int main() { 

  std::ios_base::sync_with_stdio(false);
  int n;
  cin>>n;
  //int* arr[n] = new int[n];

  set<int>s;
  
  for(int i = 0; i < n; i++) {
    int temp;
    cin>>temp;
    if(s.size() < 4) 
      s.insert(temp);
  }

  for(auto it : s)
    cout<<it<<endl;

  if(s.size() <= 2)
    cout<<"yes";
  else if(s.size() == 3) {
    vector<int> d(s.begin(), s.end());
    if(d[1] - d[0] == d[2] - d[1])cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }

  else 
    cout<<"no"<<endl;
}
