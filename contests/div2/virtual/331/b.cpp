#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  long long int sum = 0, b[200009];
  long long int n;
  
  cin>>n;

  for(long long int i = 0; i < n; i++)
    cin>>b[i];

  sum = abs(b[0]);

  for(long long int i = 1; i < n; i++)
    {
      if(b[i] != b[i-1])
	sum += abs(b[i] - b[i-1]);
    }
  
  cout<<sum<<endl;
  return 0;
}
