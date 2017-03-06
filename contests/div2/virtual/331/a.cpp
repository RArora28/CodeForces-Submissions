#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int n, i, j;
  pair<int, int> cor[5];
  
  cin>>n;

  for(i = 1; i <= n; i++)
    cin>>cor[i].first>>cor[i].second;

  if(n == 1)
    cout<<"-1"<<endl;
          
  else if(n == 2)
    {
      if(cor[1].first == cor[2].first || cor[1].second == cor[2].second)
	cout<<"-1"<<endl;
      
      else
	cout<<(abs(cor[1].first - cor[2].first) * abs(cor[1].second -  cor[2].second))<<endl;
    }
        
  else
    {
      int temp1, temp2;
      
      for(i = 1; i <= n; i++)
	{
	  for(j = 1; j <= n; j++)
	    
	    if(cor[i].first != cor[j].first && cor[i].second != cor[j].second)
	      {
		temp1 = i;
		temp2 = j;
		break;
	      }
	  
	}
      //cout<<temp1<<temp2<<endl;
      
      cout<<(abs(cor[temp1].first - cor[temp2].first) * abs(cor[temp1].second -  cor[temp2].second))<<endl;
  
    }
  return 0;
}
