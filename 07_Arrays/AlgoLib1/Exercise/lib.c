#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "lib.h"

bool all_of(int32_t *array, size_t length, int32_t value)
{
    if(array == NULL)
    {
        return false;
    }

    if(length == count(array,length,value))
    {
        return true;
    }
    else
    {
    return false;
    }
}

bool any_of(int32_t *array, size_t length, int32_t value)
{
    if(array == NULL)
    {
        return  false;
    }

    if(0 != count(array,length,value))
    {
        return true;
    }
    else
    {
    return false;
    }
}

bool none_of(int32_t *array, size_t length, int32_t value)
{
    if(array == NULL)
    {
        return  false;
    }

    if(0 == count(array,length,value))
    {
        return true;
    }
    else
    {
    return false;
    }
}

size_t count(int32_t *array, size_t length, int32_t value)//TEST => PASS
{
    if(array == NULL)
    {
        return  false;
    }

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
