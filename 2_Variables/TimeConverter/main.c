#include <stdio.h>

int main()
{
    float millisconds = 0.0F;

    printf("Please enter a millisecond value: ");
    scanf("%f", &millisconds);

    // convert_milliseconds_to_seconds
    float seconds = millisconds / 1000.0F;

    // convert_seconds_to_minutes
    float minutes = seconds / 60.0F;

    // convert_minutes_to_hours
    float hours = minutes / 60.0F;

    // convert_hours_to_days
    float days = hours / 24.0F;

    printf("seconds: %f\n", seconds);
    printf("minutes: %f\n", minutes);
    printf("hours: %f\n", hours);
    printf("days: %f\n", days);

    return 0;
}
