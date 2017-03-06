#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
  long long int n, count = 1, d1[3000], d2[3000], product = 1, temp = 0, flag = 0, xx, yy, x1, y1, x2, y2, minimum, a[3000], b[3000], x[3000], y[3000];
  
  cin>>n>>x1>>y1>>x2>>y2;

  for(int i = 0; i < n; i++)
    {
      cin>>xx>>yy;
      d1[i] = abs(x1-xx) * abs(x1 - xx) + abs(y1-yy) * abs(y1 - yy);
      d2[i] = abs(x2-xx) * abs(x2 - xx) + abs(y2-yy) * abs(y2 - yy);
    }

  a[0] = d1[0];
  x[0] = d2[0];
  
  for(int i = 1; i < n; i++)
    {
      a[i] = max(d1[i], a[i-1]);
      x[i] = max(d2[i], x[i-1]);
    }

  b[n-1] = d1[n-1];
  y[n-1] = d2[n-1];
  
  for(int i = n-2; i >= 0; i--)
    {
      b[i] = max(d1[i], b[i+1]);
      y[i] = max(d2[i], y[i+1]);
    }

  minimum = min(a[n-1], x[n-1]);
   
  for(int i = 0; i <= n-2; i++)
    minimum = min(minimum, a[i] + y[i+1]);

  //for(int i = 0; i <= n-2; i++)
  //minimum = min(minimum, x[i] + b[i+1]);
  
  cout<<minimum<<endl;
  return 0;
}
