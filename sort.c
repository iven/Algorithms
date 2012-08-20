#include <stdio.h>

#include "sort.h"
#include "utils.h"

static void heap_adjust(int array[], int length, int start)
{
  int bigger_child, left_child;

  while ((left_child = start * 2 + 1) < length) {
    if (left_child == length - 1) {
      if (array[left_child] > array[start]) {
        swap(array, start, left_child);
      }
      break;
    } else {
      bigger_child = (array[left_child] > array[left_child + 1])
        ? left_child: left_child + 1;

      if (array[bigger_child] > array[start]) {
        swap(array, start, bigger_child);
      }
      start = bigger_child;
    }
  }
}

int heap_sort(int array[], int length)
{
  for (int i = length / 2 - 1; i >= 0; i--) {
    heap_adjust(array, length, i);
  }

  printf("Adjusted Heap:\n");
  print_array(array, length);
  printf("Adjusted Heap:\n");

  for (int i = length - 1; i > 0; i--) {
    swap(array, 0, i);
    heap_adjust(array, i, 0);
  }

  return 0;
}

int shell_sort(int array[], int length)
{
  for (int gap = length / 2; gap > 0; gap--) {
    for (int i = gap; i < length; i++) {
      int j = i;
      int key = array[i];
      while ((j -= gap) >= 0 && array[j] > key) {
        array[j + gap] = array[j];
      }
      array[j + gap] = key;
    }
  }
}

int insertion_sort(int array[], int length)
{
  for (int i = 1; i < length; ++i) {
    int j = i;
    int key = array[i];
    while (--j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
    }
    array[j + 1] = key;
  }
  return 0;
}

