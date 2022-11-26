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

void unique_elements(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        return;
    }

    for (size_t i = 0; i < length; i++)
    {
        bool unique = true;
        int32_t current_value = array[i];

        for (size_t j = 0; j < length; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (current_value == array[j])
            {
                unique = false;
            }
        }

        if (unique == true)
        {
            printf("Unique element: %d\n", current_value);
        }
    }
}

void remove_duplicates(int32_t *array, size_t *length)
{
    if (array == NULL)
    {
        return;
    }

    for (size_t i = 0; i < *length; i++)
    {
        size_t duplicate_index = (size_t)(-1);
        int32_t current_value = array[i];

        for (size_t j = i + 1; j < *length; j++)
        {
            if (current_value == array[j])
            {
                duplicate_index = j;
                (*length)--;
                break;
            }
        }

        if (duplicate_index == (size_t)(-1))
        {
            continue;
        }

        for (size_t j = duplicate_index; j < *length; j++)
        {
            array[j] = array[j + 1];
        }
    }
}

void rotate_left(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        return;
    }

    int32_t first_element = array[0];

    for (size_t i = 1; i < length; i++)
    {
        array[i - 1] = array[i];
    }

    array[length - 1] = first_element;
}

void rotate_right(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        return;
    }

    int32_t last_element = array[length - 1];

    for (size_t i = length - 1; i > 0; i--)
    {
        array[i] = array[i - 1];
    }

    array[0] = last_element;
}
