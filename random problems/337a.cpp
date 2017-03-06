#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int diff(const void* a, const void* b)
{
  return (*(int*)a - *(int*)b);
}

int arr[100];

int main()
{
 int m, n, temp, min = INT_MAX, i;

  scanf("%d %d", &n, &m);

  for(i = 0; i < m; i++)
    {
      scanf("%d", &arr[i]);
    }

  min = arr[0];

  qsort(arr, m, sizeof(int), diff);
   printf("min before is %d\n", min);

  for(i = n - 1; i < m; i++)
    {
      temp = arr[i] - arr[i-(n-1)];
 
        if(temp < min)
		min = temp;

	printf("min is %d\n", min);
    }

  printf("%d\n", min);

  return 0;
}
