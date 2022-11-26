#include <stdint.h>
#include <stdio.h>

void clamp_value();

void round_value();

int main()
{
    float value = 2.0f;

    clamp_value();
    printf("%.16f\n", value);

    round_value();
    printf("%.16f\n", value);

    round_value();
    printf("%.16f\n", value);

    round_value();
    printf("%.16f\n", value);

    return 0;
}
