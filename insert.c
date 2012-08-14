#include <stdio.h>

#include "insert.h"
#include "utils.h"

int insert_sort(int array[], int length)
{
    for (int i = 1; i < length; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (array[j] > array[j + 1]) {
                swap(array, j + 1, j);
            } else {
                break;
            }
        }
    }
    return 0;
}

