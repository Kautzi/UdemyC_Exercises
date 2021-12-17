#include <stdint.h>
#include <stdio.h>

void clamp_value(float *value, float min_value, float max_value);

void round_value(float *value, uint8_t num_digits);

int main()
{
    float value1 = 2.0f;
    clamp_value(&value1, -1.33756f, 1.33756f);
    printf("%f\n", value1);

    float value2 = 2.3456789f;
    round_value(&value2, 1);
    printf("%f\n", value2);

    float value3 = 2.3456789f;
    round_value(&value3, 2);
    printf("%f\n", value3);

    float value4 = 2.3456789f;
    round_value(&value4, 3);
    printf("%f\n", value4);

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
