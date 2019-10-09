// Creating Min Heap
#include <stdio.h>
#include <stdlib.h>

void min_HeapifyTop(int i, int n, int *arr)
{
  if (i > n || 2 * i > n) {
    return;
  }
  int left, right;
  int temp, min;
  left = arr[2*i];
  if ((2 * i + 1) > n) {
    min = left < arr[i] ? left : arr[i];
  } else {
    right  = arr[2*i+1];
    min = left > right ? right > arr[i] ? arr[i] : right : left > arr[i] ? arr[i] : left;
  }
  if (min != arr[i]) {
      temp = arr[i];
      arr[i] = min;
      if (min == left) {
        arr[2*i] = temp;
        min_HeapifyTop(2*i, n, arr);
      } else {
        min_HeapifyTop(2*i, n, arr);
        arr[2*i+1] = temp;
      }
  }

  return;
}

int main()
{
  int T;
  int n;
  int k;
  int val;
  int i;
  int temp;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    int arr[n+1];
    for (i = 1; i <= n; i++) {
      scanf("%d", &arr[i]);
    }

    i = n/2;
    while (i) {
      min_HeapifyTop(i--, n, arr);
    }

    for (i = 1; i <= n; i++) {
      printf("%d  ", arr[i]);
    }

    //K deletion
    for (i = 0; i < k; i++) {
        temp = arr[n-i];
        arr[n-i] = arr[1];
        arr[1] = temp;
        min_HeapifyTop(1, n-i-1, arr);
    }

    printf("\n");
    for (i = 1; i <= n-k; i++) {
      printf("%d  ", arr[i]);
    }
    printf("\n");
  }
  return 0;
}
