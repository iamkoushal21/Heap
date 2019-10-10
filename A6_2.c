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

int main()
{
  int x = 1;
  int capacity = 2;
  int num;
  int i;
  int temp;
  int size = 1; // Will start inserting from position 1. and it will show the current elements of heap
  int *heap = calloc(capacity, sizeof(int));
  while (x != 4) {
    printf("1. Insert the element\n");
    printf("2. Delete the element\n");
    printf("3. Display the element\n");
    printf("4. Quit\n");
    scanf("%d", &x);
    switch (x) {
      case 1:
            scanf("%d", &num);
            if (capacity == size) {
              capacity = 2 * capacity;
              heap = realloc(heap, capacity * sizeof(int));
            }
            maxHeapifyBottom(size, heap, num);
            size++;
            printf("Inserted\n");

            break;
      case 2:
            scanf("%d", &num);
            int pos = search(heap, num, size);
            if (pos == -1) {
              printf("%d Not Found\n", num);
            } else {
              temp = *(heap+size-1);
              *(heap+size-1) = num;
              *(heap+pos) = temp;
              size--;
              max_HeapifyTop(pos, size - 1, heap);
              printf("Deleted\n");
            }

            break;
      case 3:
            if (size == 1) {
              printf("Empty Heap");
            }
            for (i = 1; i < size; i++) {
                printf("%d ", *(heap+i));
            }
            printf("\n");

            break;
      case 4:
            exit(0);
      default:
              break;
    }
  }
  
  return 0;
}
