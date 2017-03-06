#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
  char c[8][8];
  int temp, mina , minb, flag1 = 0, flag2 = 0, a, b, min1, min2;
  
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
      cin>>c[i][j];

  mina = INT_MAX;
  minb = mina;
  min1 = mina;
  min2 = min1;
  
  for(int j = 0; j < 8; j++)
    {
      flag1 = 0;
      flag2 = 0;
     
      for(int i = 0; i < 8; i++)
	{
          if(c[i][j] == 'B')
	    {
	      temp = 7 - i;
	       if(temp < minb)
		minb = temp;
	      flag1 = 1;
	      b = i;
	    }

	  else if(c[i][j] == 'W')
	    {
	      temp = i;
	      if(temp < mina)
		mina = temp;
	      flag2 = 1;
	      a = i;
	    }
	  
	  if(flag1 == 1 && flag2 == 1 && a >= b)
	    {
	      mina = INT_MAX;
	      minb = INT_MAX;
	    }
	}
      
      if(mina < min1)
	min1 = mina;
      if(minb < min2)
	min2 = minb;
      
    }
  cout<<min1<<endl<<min2;
  
  if(min1 <= min2)
    cout<<"A"<<endl;
  else
    cout<<"B"<<endl;
  
  return 0;
}
