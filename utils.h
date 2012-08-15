#ifndef UTILS_H
#define UTILS_H

#define GET_LENGTH(array) (sizeof(array)/sizeof(int))

void print_array(int array[], int length);

static __inline__ void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

#endif

