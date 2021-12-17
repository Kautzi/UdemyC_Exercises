# Exercise

In this exercise we will implement the following computations as recusrsive functions:

- sum of the numbers between (lower_value, upper_value)
- product of the numbers between (lower_value, upper_value)

E.g.

recursive_sum(1, 10) => 45  
recursive_product(1, 10) => 3628800  

## Main Function

```cpp
#include <stdint.h>
#include <stdio.h>

uint32_t recursive_sum(uint32_t lower_value, uint32_t upper_value);

uint32_t recursive_product(uint32_t lower_value, uint32_t upper_value);

int main()
{
    uint32_t lower_value = 1;
    uint32_t upper_value = 10;

    printf("recursive_sum: %u\n", recursive_sum(lower_value, upper_value));
    printf("recursive_product: %u\n", recursive_product(lower_value, upper_value));

    return 0;
}

```
