#include<stdio.h>
#include<stdlib.h>

int diff(const void *a, const void *b)
{
  return (*(int*)a - *(int*)b);
}


int b_search(int f[100000], int l, int r, int val)
{
  int mid;

  while ( l <= r) {

    mid = (l + r) / 2;

    if(f[mid] == val)
    {
      return mid;
    }

  else if(f[mid] > val)
    {
      r = mid - 1;
    }
  else if(f[mid] < val)
    {
      l = mid + 1;
    }
  }

  return -1;
}

int main()
{

  int m, n, a[100000], b[100000], f[100000], i, flag = 0;

  scanf("%d %d", &n, &m);

  for(i = 1; i <= n; i++)
    scanf("%d", &f[i]);

  for(i = 1; i <= m; i++)
    scanf("%d", &b[i]);

 
  qsort(f, n, sizeof(int), diff);
  
  if(m > n)
    printf("Impossible\n");

  else
    {

      for(i = 1; i <= m; i++)
	{
	   printf("no seg till here\n");
	  int temp = b_search(f, 1, n, b[i]);
	  printf();
	  if( temp == -1)
	    {
	      printf("Impossible\n");
	      break;
	    }

	  else
	    {

	      if(a[i] != -1)
		{
	  
		  a[i] = temp;
		  flag = 1;
		}

	      else
		{
		  printf("Ambiguity\n");
		  break;
		}
	    }
	}
    }

  if(flag == 1)
    {
      printf("Possible\n");
      for(i = 1; i <= m; i++)
	{
	  printf("%d", a[i]);
	}
    }
      return 0;
}
