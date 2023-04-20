#include <stdio.h>
#include <stdlib.h>


//### Func Declaration ###
float power(float num, uint32_t power); //the power func takes a float var and raise it to the power of the second value
//### END Declaration ###


//### MAIN ###
int main()
{

float x = -2.0F;
float y = -3.0F;


printf("z1=%0.5f\n",(power(x,2)+power(y,2)-(x*y)+2));
printf("z2=%0.2f\n",power((x-y),3)-3);
printf("z3=%0.2f\n",((2.0f*(power(x,3)))-(0.5*(power(x,2)))-x+4)/y);


    return 0;
}
//### END MAIN ###

//### Func Definition ###

float power(float num, uint32_t power)
{
    float result = num;//F has to be inserted because the compiler thinks as standart for floating point nums as double
    for(uint32_t i = 1; i < power;i++ )
    {
        result *= num;
    }
    return result;
}
