#include <stdint.h>
#include <stdio.h>
#include <string.h>

enum LaneAssociationType
{
    LANE_ASSOCIATION_TYPE_UNKNOWN,
    LANE_ASSOCIATION_TYPE_RIGHT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_LEFT,
};

void print_scene(float speed_mps, float distance_m, enum LaneAssociationType lane)
{
    printf("\n\n    \t  L    C    R  \n");

    const int32_t offset_m = 20;

    for (int32_t i = 100; i >= -100; i -= offset_m)
    {
        char left_string[] = "   ";
        char center_string[] = "   ";
        char right_string[] = "   ";

        switch (lane)
        {
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            if ((distance_m <= i) && (distance_m > (i - offset_m)))
            {
                strncpy(left_string, " V ", 4);
            }
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            if ((distance_m <= i) && (distance_m > (i - offset_m)))
            {
                strncpy(center_string, " V ", 4);
            }
            break;
        }
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            if ((distance_m <= i) && (distance_m > (i - offset_m)))
            {
                strncpy(left_string, " V ", 4);
            }
            break;
        }
        default:
        {
            break;
        }
        }

        printf("%d\t|%s|%s|%s|\n", i, left_string, center_string, right_string);
    }

    printf("\n");
}

int main()
{
    printf("Create the properties of a vehicle.\n");

    float speed_mps;
    printf("Speed in m/s: ");
    scanf("%f", &speed_mps);

    float distance_m;
    printf("Distabce in m: ");
    scanf("%f", &distance_m);

    uint32_t lane;
    printf("Lane (1=Right, 2=Center, 3=Left): ");
    scanf("%u", &lane);

    print_scene(speed_mps, distance_m, lane);

    return 0;
}
