#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  char str[100010];

  int len, i = 0, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, first, last;

  scanf("%s", str);

  len = strlen(str);

  first = 0;
  last = len - 1;
  
  while(first < last-2)
    {
      if(str[first] == 'A' && str[first+1] == 'B' && flag1 != 1)
	flag1 = 1;
      
      if(str[last] == 'A' && str[last-1] == 'B' && flag2 != 1)
	flag2 = 1;
      
      if(str[first] == 'B' && str[first+1] == 'A' && flag3 != 1)
	flag3 = 1;
      
      if(str[last] == 'B' && str[last-1] == 'A' && flag4 != 1)
	flag4 = 1;

      first++;
      last--;
    }

  printf("flag3 -> %d && flag4 -> %d\n", flag3, flag4);
  
  if(flag1 == 1 && flag2 == 1 || flag3 == 1 && flag4 == 1)
    printf("YES\n");
  else
    printf("NO\n");
  
    return 0;
}
