# Exercise

Implement the following functions:

```cpp
void iota(int32_t *array, size_t length, int32_t start_value);

int32_t *inclusive_scan(int32_t *array, size_t length);

int32_t *exclusive_scan(int32_t *array, size_t length);
```

- iota
  - Set the elements of an array with incrementing numbers, starting at **start_value**
  - E.g. **length** = 4, **start_value** = 1 => [1, 2, 3, 4]
  - E.g. **length** = 6, **start_value** = -2 => [-2, -1, 0, 1, 2, 3]
- Inclusive Scan
  - Sum up all elements in the **array** for index $n$ from index 0 to $n$
  - Store the result in a result array at index $n$
  - Example:  
    [1, 2, 3] => [1, 3, 6]  
    [3, 4, 5] => [2, 7, 12]
- Exclusive Scan
  - Sum up all elements in the **array** for index $n$ from index 0 to $n - 1$
  - Store the result in a result array at index $n$
  - Note: The value at index 0 of the result array is always 0
  - Example:  
    [1, 2, 3] => [0, 1, 3]  
    [3, 4, 5] => [0, 3, 7]

Note: Make sure that the input pointers are valid.

## Main Function

```cpp
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
```
