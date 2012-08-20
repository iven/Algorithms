#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "sort.h"
#include "utils.h"

int main(void)
{
  int array[] = {5, 2, 4, 6, 1, 9, 7, 8, 3, 0};
  int length = GET_LENGTH(array);

  //insertion_sort(array, length);
  //shell_sort(array, length);
  //heap_sort(array, length);
  merge_sort(array, length);

  printf("Sorted Heap:\n");
  print_array(array, GET_LENGTH(array));

  return EXIT_SUCCESS;
}

