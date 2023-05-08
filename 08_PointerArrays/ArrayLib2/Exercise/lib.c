#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

bool array_equal(int32_t *array1,
                 size_t length1,
                 int32_t *array2,
                 size_t length2)// TEST => PASS
{
    //check if array1 and 2 are valid
    if(array1 == NULL || array2 == NULL)
    {
        return false;
    }
    if(length1 != length2)
    {
        return false;
    }

    for(size_t i = 0; i < length1; i++)
    {
        if(array1[i]==array2[i])
        {
            continue;

        }
        else
        {
            return false;
        }

    }
    return true;
}

void array_clamp(int32_t *array,
                 size_t length,
                 int32_t min_value,
                 int32_t max_value)// TEST => PASS
{
    if(array == NULL)
    {
        return;
    }
    //now check every element of array if it is lower min_value if than set the element to min_value
    //else the element is >= max_value set to max_value
    for(size_t i = 0; i < length; i++)
    {
        if(array[i] < min_value)
        {
            array[i]= min_value;
        }
        else if(array[i] > max_value)
        {
            array[i]=max_value;
        }

    }
    return;
}

void array_reverse(int32_t *array, size_t length)// TEST => PASS
{
    //change direction of array first to last and so on
    if(array == NULL)
    {
        return;
    }
    int32_t temp = 0;

    for(size_t i = 0; i < length/2; i++)
    {
        temp = array[i];
        array[i]=array[length-1-i];
        array[length-1-i]=temp;

    }

}

void array_fill_n(int32_t *array, size_t length, size_t n, int32_t value) // TEST => PASS
{
    if(array == NULL)
    {
        return;
    }
    if(n > length)
    {
        n = length;
    }
    for(size_t i = 0; i < n;i++)
    {
        array[i]=value;
    }
}
