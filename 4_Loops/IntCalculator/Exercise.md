# Exercise

In this exercise, you have to use an **int** datatype for certain computations.

Implement the following functions:

```cpp
uint32_t modulo(uint32_t number_a, uint32_t number_b);

uint32_t sum_of_digits(uint32_t number);

uint32_t cross_sum(uint32_t number);
```

- Modulo
  - Implement the modulo operator (a % b = c)
  - E.g. 10 % 4 = 2, 10 % 3 = 1, 10 % 2 = 0
- Sum Of Digits
  - Number of decimal digits
  - E.g. 128 = 3 Digits
- Cross Sum (*Quersumme*)
  - Add up all decimal digits
  - E.g. 123 = 6, 1234 = 10

Note:

The datatype uint32_t is defined in the **stdint.h** header file.

```cpp
#include <stdint.h>

uint32_t i = 0;
```

These datatypes ensure that for every operating system and compiler the value range is the same (for exactly this type 32 bit).

## Main Function

```cpp
int main()
{
    uint32_t input_number = 0;

    printf("Please enter a unsinged integer: ";
    scanf("%d", &input_number;

    printf(input_number << " % 3: " << modulo(input_number, 3) << endl;
    printf("sum_of_digits: " << sum_of_digits(input_number) << endl;
    printf("cross_sum: " << cross_sum(input_number) << endl;
}
```
