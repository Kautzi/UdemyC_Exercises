#include <iomanip>
#include <math.h>
#include <stdio.h>

double calculate_pi(uint32_t num_iterations);

void print_dec_to_bin(uint8_t value);

int main()
{
    uint32_t num_iterations = 1'000'000;
    double pi = 3.14159265358979323846;
    double pi_calculated = calculate_pi(num_iterations);

    printf("pi (calculated): %d", pi_calculated);
    printf("pi (correct): %d", pi);

    uint8_t dec = 0b10001110;
    print_dec_to_bin(dec);
}

double calculate_pi(uint32_t num_iterations)
{
    double result = 0.0;

    for (uint32_t k = 0; k < num_iterations; k++)
    {
        result += (1.0 / (4.0 * k + 1.0)) - (1.0 / (4.0 * k + 3.0));
    }

    return result * 4.0;
}

void print_dec_to_bin(uint8_t value)
{
    printf("Binary: 0b");

    for (int8_t i = 7; i >= 0; i--)
    {
        uint8_t current_exponent = pow(2, i);

        if (current_exponent <= value)
        {
            printf("1");
            value -= current_exponent;
        }
        else
        {
            printf("0");
        }
    }

    printf("\n");
}
