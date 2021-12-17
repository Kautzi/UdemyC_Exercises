#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "AdFunctions.h"
#include "AdTypes.h"

void print_scene(float speed_mps, uint32_t lane_idx)
{
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
}
