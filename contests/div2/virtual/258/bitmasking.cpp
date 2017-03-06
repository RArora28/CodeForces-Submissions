#include<bits/stdc++.h>
using namespace std;

int N;
int arr[1000];

void bitmask(int i, int arr[]) {

  if(i == N+1) {
    for(int j = 1; j <= N; j++)
      cout<<arr[j]<<" ";
    cout<<endl;
    return;
  }

  arr[i] = 1;
  bitmask(i+1, arr);
  arr[i] = 0;
  bitmask(i+1, arr);

  return;
}

int main() {

  cin>>N;

  bitmask(1, arr);
  
  return 0;
  
}
