#include <stdio.h>

int main()
{
    float x = -2.0f;
    float y = -3.0f;

    // 1.)
    float z1 = x * x + y * y - (x * y) + 2;
    printf("%f\n", z1);

    // 2.)
    float z2 = (x - y) * (x - y) * (x - y) - 3;
    printf("%f\n", z2);

    // 3.)
    float z3 = (2 * x * x * x - 0.5 * x * x - x + 4) / y;
    printf("%f\n", z3);

    return 0;
}
