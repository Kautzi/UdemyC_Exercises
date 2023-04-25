#include <math.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
    // calculate_pi
    uint32_t num_iterations = 1000000;
    double pi_calculated = 0.0;

    for(uint32_t i = 0; i < num_iterations; i++)
    {
        pi_calculated += (1.0/(4.0*i+1)) - (1.0/(4.0*i+3));
    }

    double pi = 3.14159265358979323846;
    printf("pi (calculated): %lf\n", pi_calculated*4);
    printf("pi (correct): %lf\n", pi);

    // print_dec_to_bin
    uint8_t dec = 142;


    return 0;
}
