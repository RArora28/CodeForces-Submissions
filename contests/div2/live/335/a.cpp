#include<iostream>
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int a, b, c, x, y, z , s = 0;

  scanf("%d %d %d", &a, &b ,&c);
  scanf("%d %d %d", &x, &y ,&z);

  if(a >= x)
    s += x + (a - x) / 2;
  else
    s += a;

  if(b >= y)
    s += y + (b - y) / 2;
  else
    s += b;

  if(c >= z)
    s += z + (c - z) / 2;
  else
    s += c;

  if(s >= (x + y + z))
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
