#include<stdio.h>

int main() {

  int n, k, i, temp, sum = 0, a[100];

  scanf("%d %d", &n, &k);

  for(i = 0; i < n; i++) {
    
    scanf("%d", &a[i]);
    
    if(i == k-1)
	temp = a[i];
  }

  for(i = 0; i < n; i++) {

    if(a[i] >= temp && a[i] > 0)
      sum++;

    else if(a[i] < temp)
      break;
  }

  printf("%d\n", sum);

  return 0;
}
