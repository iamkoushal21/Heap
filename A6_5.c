//Heap Sort
#include <stdio.h>
#include <stdlib.h>

void max_HeapifyTop(int i, int n, int *arr, int *count)
{
  if (i > n || 2 * i > n) {
    return;
  }
  int left, right;
  int temp, max;
  left = arr[2*i];
  if ((2 * i + 1) > n) {
    max = left > arr[i] ? left : arr[i];
  } else {
    right  = arr[2*i+1];
    max = left < right ? right < arr[i] ? arr[i] : right : left < arr[i] ? arr[i] : left;
  }
  if (max != arr[i]) {
      *count = *count + 1;
      temp = arr[i];
      arr[i] = max;
      if (max == left) {
        arr[2*i] = temp;
        max_HeapifyTop(2*i, n, arr, count);
      } else {
        arr[2*i+1] = temp;
        max_HeapifyTop(2*i+1, n, arr, count);
      }
  }

  return;
}

int main()
{
  int T;
  int n;
  int val;
  int i;
  int temp;
  int count = 0;
  scanf("%d", &T);
  while (T--) {
    count = 0;
    scanf("%d", &n);
    int arr[n+1];
    for (i = 1; i <= n; i++) {
      scanf("%d", &arr[i]);
    }

    i = n/2;
    while (i) {
      max_HeapifyTop(i--, n, arr, &count);
    }
    printf("%d\n", count);

    printf("\n");
    for (i = 1; i <= n; i++) {
      printf("%d ", arr[i]);
    }
  }

  return 0;
}
