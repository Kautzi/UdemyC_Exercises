#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

void unique_elements(int32_t *array, size_t length);

void remove_duplicates(int32_t *array, size_t *length);

void rotate_left(int32_t *array, size_t length);

void rotate_right(int32_t *array, size_t length);

int main()
{
    int32_t array[] = {1, 1, 2, 3, 3, 4};
    size_t length = 6;

    printf("unique_elements: \n");
    unique_elements(array, length);

    remove_duplicates(array, &length);
    print_int32_array(array, length);

    rotate_left(array, length);
    print_int32_array(array, length);

    rotate_right(array, length);
    print_int32_array(array, length);

    return 0;
}
