#include <stdint.h>

#include "lib.h"

void clamp_value(float *value, float min_value, float max_value)
{
    if(*value < min_value)
    {
        *value= min_value;
    }
    else if (*value > max_value)
    {
        *value = max_value;
    }
    return;
}

void round_value(float *value, uint8_t num_digits)
{
    int64_t exp = 1;
    for(uint8_t i = 0; i < num_digits;i ++)
    {
    exp*=10;
    }
    int64_t temp =(int64_t) ((*value)* (float)exp);

    *value = (float)temp/(float)exp;
    return;
}
