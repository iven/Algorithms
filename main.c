#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "insert.h"

#define ARRAY_LENGTH 10

int main(void)
{
    int array[ARRAY_LENGTH] = {5, 2, 4, 6, 1, 9, 7, 8, 3, 0};
    insert_sort(array, ARRAY_LENGTH);

    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        printf("%d\n", array[i]);
    }
    return EXIT_SUCCESS;
}

