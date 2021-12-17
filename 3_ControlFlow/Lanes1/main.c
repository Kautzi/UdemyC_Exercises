#include <stdint.h>
#include <stdio.h>

enum LaneAssociationType
{
    LANE_ASSOCIATION_TYPE_NONE,
    LANE_ASSOCIATION_TYPE_LEFT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_RIGHT,
};

int main()
{
    printf("Create the properties of a vehicle.\n");

    float speed_mps;
    printf("Speed in m/s: ");
    scanf("%f", &speed_mps);

    uint32_t lane_idx;
    printf("Lane (1=Right, 2=Center, 3=Left): ");
    scanf("%u", &lane_idx);

    printf("\n\n    \t  L   C   R  \n");
    switch (lane_idx)
    {
    case LANE_ASSOCIATION_TYPE_LEFT:
    {
        printf("\t| V |   |   |\n");
        break;
    }
    case LANE_ASSOCIATION_TYPE_CENTER:
    {
        printf("\t|   | V |   |\n");
        break;
    }
    case LANE_ASSOCIATION_TYPE_RIGHT:
    {
        printf("\t|   |   | V |\n");
        break;
    }
    default:
    {
        break;
    }
    }

    printf("\n");
    printf("Speed: %f\n", speed_mps);
    printf("\n");

    return 0;
}
