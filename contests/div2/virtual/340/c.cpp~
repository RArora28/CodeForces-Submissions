#include<iostream>
using namespace std;

int main()
{
  long long int n, count = 1, a[150], product = 1, temp = 0, flag = 0;
  
  cin>>n;

  for(int i = 0; i < n; i++)
    {
      cin>>a[i];

      if(a[i] == 0 && i != 0 && i != n-1 && flag == 1)
	count++;
      
      else if(a[i] == 1)
	{
	  flag = 1;
	  temp++;
	  product *= count;
	  count = 1;
	}  
    }

  if(temp == 0)
    cout<<"0"<<endl;

  else
    cout<<product<<endl;
    
  return 0;
}
