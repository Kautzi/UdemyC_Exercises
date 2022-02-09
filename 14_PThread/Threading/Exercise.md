# Exercise

Implement a function that computes the sum of an array with and without threading.

## Main Function

```cpp
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//...

int main()
{
    float *arr = (float *)malloc(LENGTH * sizeof(float));

    for (size_t i = 0; i < LENGTH; i++)
    {
        if ((i % 2) == 0)
        {
            arr[i] = 1.0F;
        }
        else
        {
            arr[i] = -1.0F;
        }
    }

    double total_time = 0.0;

    const time_t start = time(NULL);
    for (uint32_t run_idx = 0; run_idx < NUM_RUNS; run_idx++)
    {
        (void)serial_sum(arr, LENGTH);
    }
    const time_t end = time(NULL);
    total_time = (difftime(end, start) * 1000.0F) / (double)(NUM_RUNS);

    printf("Serial - Mean execution time: %.2lf ms\n", total_time);

    total_time = 0.0;

    const time_t start = time(NULL);
    for (uint32_t run_idx = 0; run_idx < NUM_RUNS; run_idx++)
    {
        (void)parallel_sum(arr, LENGTH);
    }
    const time_t end = time(NULL);
    total_time = (difftime(end, start) * 1000.0F) / (double)(NUM_RUNS);

    printf("Parall - Mean execution time: %.2lf ms\n", total_time);

    free(arr);
    arr = NULL;

    return 0;
}
```
