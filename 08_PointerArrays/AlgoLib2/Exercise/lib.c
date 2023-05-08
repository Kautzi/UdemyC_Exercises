#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

void iota(int32_t *array, size_t length, int32_t start_value)
{
    if(array == NULL)
    {
        return;
    }

    bool is_element = false;
    int32_t temp = 0;
    size_t index_value_found;

    for(size_t i = 0; i < length; i++ )
    {
        if(array[i]== start_value)
        is_element = true;
        temp = array[0];
        index_value_found = i;

    }
    if(is_element)
    {

    }

}

int32_t *inclusive_scan(int32_t *array, size_t length)
{
}
