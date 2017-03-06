#include<iostream>
using namespace std;

int main()
{
  int m, s;
  cin>>m>>s;

  int i = 9, arr[m], index = 0;

  if(m == 1 && s == 0)
    cout<<"0 0";
  else if(9 * m < s || s == 0)
    cout<<"-1 -1";
  else
    {
      int mtemp = m;
      
      while(m > 0)
	{
	  s = s - i;
      
	  if(s >= 0)
	    {
	      arr[index++] = i;
	      m--;
	      if(s == 0)
		break;
	    }
      
	  else if(s < 0)
	    {
	      s = s + i;
	      i--;
	    }
	}
      int index1 = index;
      int index2 = index;

      cout<<arr[index-1];
      
      while(index1 < mtemp)
	{
	  cout<<"0";
	  index1++;
	}
      for(int i = index-2; i >= 0; i--)
	cout<<arr[i];
      
       cout<<" ";
       
      for(int i = 0; i < index; i++)
	cout<<arr[i];

      while(index2 < mtemp)
	{
	  cout<<"0";
	  index2++;
	}
    }
  cout<<endl;
  return 0;
}
