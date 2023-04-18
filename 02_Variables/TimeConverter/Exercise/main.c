#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//### Types ###
typedef struct time_conv
{
    uint32_t hour;
    uint32_t min;
    uint32_t sec;
    uint32_t mills;
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


    printf("Milliseconds: %d\n",time->mills);
    printf("Seconds: %d\n",time->sec);
    printf("Minutes: %d\n",time->min);
    printf("Hours: %d\n",time->hour);
    printf("Milliseconds: %d\n",time->mills);

    free(time);
    return 0;
}
//### END MAIN ###

//### Function Definition ###
time_conv_t *time_conv(float mills)
{
    time_conv_t *time = (time_conv_t*)malloc(sizeof(time_conv_t));
    time->mills = (uint32_t)mills;
    time->sec = (uint32_t)mills / 1000;
    time->min = time->sec / 60;
    time->hour = time->min / 60;

    return time;
}
