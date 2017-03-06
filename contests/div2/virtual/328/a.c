#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
  char c[9][9];
  int temp, mina , minb, flag1, flag;
  
  for(int i = 1; i <= 8; i++)
    for(int j = 1; j <= 8; j++)
      cin>>c[i][j];

  
  for(int j = 1; j <= 8; j++)
    {
      flag1 = 0;
      flag2 = 0;
      minb = INT_MAX;
      mina = minb;
      
      for(int i = 1; i <= 8; i++)
	{
	  if(c[i][j] == 'B')
	    {
	      temp = 8 - i;
	      if(temp < minb)
		minb = temp;
	      flag1 = 1;
	    }
	  else if(c[i][j] == 'W')
	    {
	      temp = i - 1;
	      if(temp < mina)
		mina = temp;
	      flag2 = 1;
	    }
	  if(flag1 == 1 && flag2 == 1)
	    {
	      mina = INT_MAX;
	      minb = INT_MAX;
	      break;
	    }
	}
    }
  if(mina <= minb)
    cout<<"A"<<endl;
  else
    cout<<"B"<<endl;
  
  return 0;
}
