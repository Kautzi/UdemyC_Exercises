#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

void iota(int32_t *array, size_t length, int32_t start_value)// TEST => PASS
{
    if(array == NULL)
    {
        return;
    }

    for(size_t i = 0; i < length; i++)
    {
        array[i] = start_value;
        start_value ++;
    }
}

int32_t *inclusive_scan(int32_t *array, size_t length)
{
    if(array == NULL)
    {
        return NULL;
    }
    int32_t * sum_result = (int32_t*)malloc(sizeof(int32_t)*length);
    if(sum_result == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < length; i++)
    {
        if(i == 0)
        {
            sum_result[i] = array[i];
        }
        else
        {
        sum_result[i]=sum_result[i-1]+array[i];
        }
    }

    return sum_result;
}
