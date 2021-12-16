# Exercise

Implement the following functions:

```cpp
bool all_of(int32_t *array, size_t length, int32_t value);

bool any_of(int32_t *array, size_t length, int32_t value);

bool none_of(int32_t *array, size_t length, int32_t value);

size_t count(int32_t *array, size_t length, int32_t value);

int32_t *inclusive_scan(int32_t *array, size_t length);
```

- All Of
  - Returns true if all elements in the array are equal to the **value**
  - E.g. all_of([1, 1, 1], 3, 1) => true
  - E.g. all_of([1, 1, 2], 3, 1) => false
- Any Of
  - Returns true if at least one element in the array is equal to the **value**
  - E.g. any_of([1, 1, 1], 3, 1) => true
  - E.g. any_of([1, 1, 2], 3, 1) => true
- None Of
  - Returns true if all elements in the array are not equal to the **value**
  - E.g. none_of([1, 1, 1], 3, 1) => false
  - E.g. none_of([1, 1, 2], 3, 1) => false
- Count
  - Counts the elements in the array that are equal to the **value**
  - E.g. count([1, 1, 1], 3, 1) => 3
  - E.g. count([1, 1, 2], 3, 1) => 2
- Inclusive Scan
  - Sum up all elements in the array for index $n$ from 0 to $n-1$
  - The result is stored and returned in a new array
  - Example:  
    [1, 2, 3] => [1, 3, 6]  
    [3, 4, 5] => [2, 7, 12]

Note: Make sure that the input pointers are valid.

## Main Function

```cpp
int main()
{
    int32_t array[] = {3, 1, 4, 1, 5, 9, 2, 6};
    size_t length = 8;

    printf("all_of: %d\n", all_of(array, length, 5));
    printf("any_of: %d\n", any_of(array, length, 5));
    printf("none_of: %d\n", none_of(array, length, 5));
    int32_t *scan_values = inclusive_scan(array, length);
    printf("inclusive_scan: \n");
    print_int32_array(scan_values, length);

    free(scan_values);
    scan_values = NULL;

    return 0;
}
```
