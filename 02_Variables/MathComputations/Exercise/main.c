#include <stdio.h>
#include <stdlib.h>


//### Func Declaration ###
float power(float num, uint32_t power); //the power func takes a float var and raise it to the power of the second value
//### END Declaration ###


//### MAIN ###
int main()
{
float res=0.0f;
float x = -2.0F;
float y = -3.0F;


printf("%0.5f\n",power(2,5));

    return 0;
}
//### END MAIN ###

//### Func Definition ###

float power(float num, uint32_t power)
{
    float result = num;//F has to be inserted because the compiler thinks as standart for floating point nums as double
    for(uint32_t i = 0; i < power;i++ )
    {
        result *= num;
    }
    return result;
}
