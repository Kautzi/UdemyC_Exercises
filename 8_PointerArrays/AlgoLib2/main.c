#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void iota(int32_t *array, size_t length, int32_t start_value);

int32_t *inclusive_scan(int32_t *array, size_t length);

int32_t *exclusive_scan(int32_t *array, size_t length);

int main()
{
    int32_t array[8] = {0};
    size_t length = 8;

    iota(array, length, 0);
    print_int32_array(array, length);

    int32_t *inc_scan_values = inclusive_scan(array, length);
    printf("inclusive_scan: \n");
    print_int32_array(inc_scan_values, length);

    int32_t *exc_scan_values = exclusive_scan(array, length);
    printf("exclusive_scan: \n");
    print_int32_array(exc_scan_values, length);

    free(inc_scan_values);
    inc_scan_values = NULL;

    free(exc_scan_values);
    exc_scan_values = NULL;

    return 0;
}

void iota(int32_t *array, size_t length, int32_t start_value)
{
    for (size_t i = 0; i < length; i++)
    {
        array[i] = start_value;

        start_value++;
    }
}

int32_t *inclusive_scan(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        return NULL;
    }

    int32_t *result = (int32_t *)malloc(length * sizeof(int32_t));

    result[0] = array[0];

    for (size_t i = 1; i < length; i++)
    {
        result[i] = result[i - 1] + array[i];
    }

    return result;
}

int32_t *exclusive_scan(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        return NULL;
    }

    int32_t *result = (int32_t *)malloc(length * sizeof(int32_t));

    result[0] = 0;

    for (size_t i = 1; i < length; i++)
    {
        result[i] = result[i - 1] + array[i - 1];
    }

    return result;
}
