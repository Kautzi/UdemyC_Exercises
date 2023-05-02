#include <stdint.h>
#include <stdio.h>

#include "AdFunctions.h"
#include "AdTypes.h"

void print_scene(float speed_mps, uint32_t lane_idx)
{
    printf("\n\n");
    printf("\t  L   C   R\n");

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
    case LANE_ASSOCIATION_TYPE_NONE:
    default:
    {
        printf("\t|   |   |   |\n");
        break;
    }
    }

    printf("\n");
    printf("Speed: %f\n", speed_mps);
    printf("\n");
}

LaneAssociationType_t handle_lateral_user_input(LaneAssociationType_t lane_idx,LateraAction_t lateral_action)
{
switch(lateral_action)
{
    case a://LEFT
    {
        if (lane_idx == LANE_ASSOCIATION_TYPE_LEFT)
        {
            break;
        }
        else
        {
            lane_idx--;
        }

    break;
    }
    case d://Right
    {
        if (lane_idx == LANE_ASSOCIATION_TYPE_RIGHT)
        {
            break;
        }
        else
        {
            lane_idx++;
        }

    break;
    }
    case c://NONE
    default:
    {
        break;
    }


}

return lane_idx;
}

float handle_longitudinal_user_input(float speed_mps,LongitudinalAction_t de_increase_none);
