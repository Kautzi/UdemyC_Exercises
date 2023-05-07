#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


#include "lib.h"

void unique_elements(int32_t *array, size_t length)
{
int32_t temp_array[length];
size_t temp_length = length;
//copy array to temp_array
for(size_t i = 0; i < length; i++)
{
    temp_array[i]=array[i];
}

remove_duplicates(temp_array,&temp_length);
for(size_t j = 0; j < temp_length; j++)
{
printf("%d, ",temp_array[j]);
}
printf("\n");
}

void remove_duplicates(int32_t *array, size_t *length)
{
   if(array == NULL || length == NULL)
   {
    return;
   }
    size_t temp_length = *length;
   for(size_t i = 0; i < temp_length;i++)
   {
        if(array[0]==array[1])
        {
            rotate_left(array,*length);
            *length=*length - 1;
        }
        else
        {
        rotate_left(array,*length);
        }

   }


   return;
}

void rotate_left(int32_t *array, size_t length)//TEST =>PASS
{
    if(array == NULL)
    {
        return;
    }
    //copy all elements to temp_array
    int32_t temp_array[length];

    for(size_t i = 0; i < length; i++)
    {
        temp_array[i]=array[i];
    }

    for(size_t j = 0; j < length;j ++)
    {
        if(j != length - 1)
        {
        array[j]=temp_array[j+1];
        }
        else
        {
            array[length-1]=temp_array[0];
        }
    }

    return;
}

void rotate_right(int32_t *array, size_t length)//TEST => PASS
{
    if(array == NULL)
    {
        return;
    }
    int32_t temp_array[length];

    for(size_t i = 0; i < length; i++)
    {
        temp_array[i]=array[i];
    }

    for(size_t j = 0; j < length;j ++)
    {
        if(j == 0)
        {
            array[j]= temp_array[length-1];
        }
        else
        {
            array[j]=temp_array[j-1];
        }
    }

return;
}
