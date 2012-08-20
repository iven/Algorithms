#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  return 0;
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

static void merge(int array[], int temp_array[], int length)
{
  int left = length / 2;
  int i = 0, j = left, k = 0;

  memcpy(temp_array, array, left * sizeof(int));

  while (i < left && j < length)
  {
    if (temp_array[i] > array[j]) {
      array[k++] = array[j++];
    } else {
      array[k++] = temp_array[i++];
    }
  }
  if (i < left) {
    memcpy(array + k, temp_array + i, left - i);
  }
}

static void _merge_sort(int array[], int temp_array[], int length)
{
  if (length > 1) {
    int left = length / 2, right = length - left;
    _merge_sort(array, temp_array, left);
    _merge_sort(array + left, temp_array, right);
    merge(array, temp_array, length);
  }

}

int merge_sort(int array[], int length)
{
  int *temp_array;

  temp_array = malloc(length * sizeof(int));

  _merge_sort(array, temp_array, length);

  free(temp_array);

  return 0;
}

