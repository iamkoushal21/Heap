// This is a Max heap dyanmically adding and deleting elements.
#include <stdio.h>
#include <stdlib.h>

void maxHeapifyBottom(int pos, int *heap, int num)
{
  int parentpos;
  if (pos == 0) {
    return;
  }
  *(heap+pos) = num;
  parentpos = pos / 2;
  if (*(heap+parentpos) < num && parentpos > 0) {
    *(heap+pos) = *(heap+parentpos);
    *(heap+parentpos) = num;
    maxHeapifyBottom(parentpos, heap, num);
  }

  return;
}
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
        arr[2*i+1] = temp;
        max_HeapifyTop(2*i+1, n, arr);
      }
  }

  return;
}

int search(int *heap, int num, int size)
{
  int i;
  for (i = 1; i < size; i++) {
      if (*(heap+i) == num) {
          return i;
      }
  }

  return -1;
}
