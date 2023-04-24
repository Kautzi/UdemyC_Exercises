#include <stdint.h>
#include <stdio.h>

//### Function Declaration ###
uint32_t sum_of_digits(uint32_t num);
uint32_t cross_sum(uint32_t num, uint32_t digits);
//### END Function Declaration ###


//### MAIN ###
int main()
{
    uint32_t number = 0;

    printf("Please enter a unsinged integer: ");
    scanf("%u", &number);

    // sum_of_digits
    uint32_t num_digits = sum_of_digits(number);

    printf("sum_of_digits: %u\n", num_digits);

    // cross_sum
    uint32_t cros_sum = cross_sum(number,num_digits);

    printf("cross_sum: %d\n", cros_sum);
}
//### END MAIN ###

//### Function Definition ###

uint32_t sum_of_digits(uint32_t num)
{
    uint32_t compare = 1;
    uint32_t digits = 1;
    while(num >= compare)
    {
        compare *=10;
        if(compare <=num)
        {
        digits++;
        }
    }
    return digits;
}

uint32_t cross_sum(uint32_t num, uint32_t digits)
{   uint32_t cross_sum=0;
    uint32_t modulo_teiler= 10;
    for(uint32_t i = 0 ; i < digits;i++)
    {
    cross_sum += num % modulo_teiler;
    num-= (num % modulo_teiler);
    num= num /modulo_teiler;

    }
    return cross_sum;
}
