#include <stdio.h>

#include "insert.h"
#include "utils.h"

int insert_sort(int array[], int length)
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

