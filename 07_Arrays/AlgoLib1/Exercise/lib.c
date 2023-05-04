#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "lib.h"

bool all_of(int32_t *array, size_t length, int32_t value)
{
    return true;
}

bool any_of(int32_t *array, size_t length, int32_t value)
{
    return true;
}

bool none_of(int32_t *array, size_t length, int32_t value)
{
    return true;
}

size_t count(int32_t *array, size_t length, int32_t value)//TEST => PASS
{
    size_t count_equal = 0;
    for(size_t i = 0; i < length ;i++)
    {
    if(array[i]== value)
    {
        count_equal++;
    }

    }
    return count_equal;
}
