#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//### Types ###
typedef struct time_conv
{
    float hour;
    float min;
    float sec;
    float mills;
    float day;
}time_conv_t;
//### END TYPES ###

//### Function declaration
time_conv_t *time_conv(float mills);
//### END Declaration



//### MAIN ###
int main()
{
//### Variables ###
float mills;

    printf("Please enter a millisecond Value:\n");
    scanf("%f",&mills);
    time_conv_t* time = time_conv(mills);


    printf("Milliseconds: %0.5f\n",time->mills);
    printf("Seconds: %0.5f\n",time->sec);
    printf("Minutes: %0.5f\n",time->min);
    printf("Hours: %0.5f\n",time->hour);
    printf("Day: %0.5f\n",time->day);


    free(time);
    return 0;
}
//### END MAIN ###

//### Function Definition ###
time_conv_t *time_conv(float mills)
{
    time_conv_t *time = (time_conv_t*)malloc(sizeof(time_conv_t));
    time->mills = mills;
    time->sec = mills / 1000.0F; //remember to set an F course only 1000.0 is interpreated as double by the compiler as default
    time->min = time->sec / 60.0F;
    time->hour = time->min / 60.0F;
    time->day = time->hour /24.0f;

    return time;
}
