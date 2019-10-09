//Heap Sort
#include <stdio.h>
#include <stdlib.h>

void max_HeapifyTop(int i, int n, int *arr)
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
      temp = arr[i];
      arr[i] = max;
      if (max == left) {
        arr[2*i] = temp;
        max_HeapifyTop(2*i, n, arr);
      } else {
        max_HeapifyTop(2*i, n, arr);
        arr[2*i+1] = temp;
      }
  }

  return;
}
