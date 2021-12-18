#include <stdint.h>
#include <stdio.h>

void clamp_value(float *value, float min_value, float max_value);

void round_value(float *value, uint8_t num_digits);

int main()
{
    float value = 2.0f;

    clamp_value(&value, -1.34567f, 1.24567f);
    printf("%.16f\n", value);

    round_value(&value, 3);
    printf("%.16f\n", value);

    round_value(&value, 2);
    printf("%.16f\n", value);

    round_value(&value, 1);
    printf("%.16f\n", value);

    return 0;
}

void clamp_value(float *value, float min_value, float max_value)
{
    if (*value < min_value)
    {
        *value = min_value;
    }
    else if (*value > max_value)
    {
        *value = max_value;
    }
}

void round_value(float *value, uint8_t num_digits)
{
    float multiplier = 1.0f;

    for (uint8_t i = 0; i < num_digits; i++)
    {
        multiplier *= 10.0f;
    }

    uint32_t temp = (*value) * multiplier;

    *value = temp / multiplier;
}
