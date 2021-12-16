#include <stdio.h>

float convert_milliseconds_to_seconds(float millisconds);

float convert_seconds_to_minutes(float seconds);

float convert_minutes_to_hours(float minutes);

float convert_milliseconds_to_minutes(float millisconds);

float convert_milliseconds_to_hours(float millisconds);

float convert_seconds_to_hours(float seconds);

int main()
{
    float input_milliseconds = 0.0F;

    printf("Please enter a millisecond value: ");
    scanf("%f", &input_milliseconds);

    float seconds = convert_milliseconds_to_seconds(input_milliseconds);
    float minutes = convert_seconds_to_minutes(seconds);
    float Hours = convert_minutes_to_hours(minutes);

    float minutes2 = convert_milliseconds_to_minutes(input_milliseconds);
    float hours2 = convert_milliseconds_to_hours(input_milliseconds);
    float hours3 = convert_seconds_to_hours(seconds);

    printf("seconds: %f\n", seconds);
    printf("minutes: %f\n", minutes);
    printf("Hours: %f\n", Hours);

    printf("minutes2: %f\n", minutes2);
    printf("hours2: %f\n", hours2);
    printf("hours3: %f\n", hours3);

    return 0;
}

float convert_milliseconds_to_seconds(float millisconds)
{
    return millisconds / 1000.0F;
}

float convert_seconds_to_minutes(float seconds)
{
    return seconds / 60.0F;
}

float convert_minutes_to_hours(float minutes)
{
    return minutes / 60.0F;
}

float convert_milliseconds_to_minutes(float millisconds)
{
    float seconds = convert_milliseconds_to_seconds(millisconds);
    float minutes = convert_seconds_to_minutes(seconds);

    return minutes;
}

float convert_milliseconds_to_hours(float millisconds)
{
    float seconds = convert_milliseconds_to_seconds(millisconds);
    float minutes = convert_seconds_to_minutes(seconds);
    float hours = convert_minutes_to_hours(minutes);

    return hours;
}

float convert_seconds_to_hours(float seconds)
{
    float minutes = convert_seconds_to_minutes(seconds);
    float hours = convert_minutes_to_hours(minutes);

    return hours;
}
