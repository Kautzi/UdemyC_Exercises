#include <math.h>
#include <stdint.h>
#include <stdio.h>

uint32_t modulo(uint32_t number_a, uint32_t number_b);

uint32_t sum_of_digits(uint32_t number);

uint32_t cross_sum(uint32_t number);

int main()
{
    uint32_t input_number = 0;

    printf("Please enter a unsinged integer: ");
    scanf("%d", &input_number);

    uint32_t result = modulo(input_number, 3);
    printf("%d %% 3 = %d", input_number, result);
    printf("sum_of_digits: %d", sum_of_digits(input_number));
    printf("cross_sum: %d", cross_sum(input_number));
}

uint32_t modulo(uint32_t number_a, uint32_t number_b)
{
    uint32_t result = 0;
    uint32_t divisor = number_a / number_b;

    result = number_a - number_b * divisor;

    return result;
}

uint32_t sum_of_digits(uint32_t number)
{
    uint32_t num_digits = 0;

    while (number > 0)
    {
        number /= 10;
        num_digits++;
    }

    return num_digits;
}

uint32_t cross_sum(uint32_t number)
{
    uint32_t sum = 0;

    while (number > 0)
    {
        uint32_t current_digit = number % 10;

        sum += current_digit;

        number /= 10;
    }

    return sum;
}
