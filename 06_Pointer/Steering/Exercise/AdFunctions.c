#include <stdint.h>
#include <stdio.h>

#include "AdFunctions.h"
#include "AdTypes.h"
#include "AdConstants.h"

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
    case LATERAL_ACTION_TYPE_LEFT://LEFT
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
    case LATERAL_ACTION_TYPE_RIGTH://Right
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
    case LATERAL_ACTION_TYPE_NONE://NONE
    default:
    {
        break;
    }


}

return lane_idx;
}

float handle_longitudinal_user_input(float speed_mps,LongitudinalAction_t de_increase_none)
{

switch(de_increase_none)
{
    case LONGITUDINAL_ACTION_INCREASE:
    {
        speed_mps +=speed_mps * LONGITUDINAL_DIFFERENCE_PERCENTAGE;
        break;
    }

    case LONGITUDINAL_ACTION_DECREASE:
    {
        speed_mps -=speed_mps * LONGITUDINAL_DIFFERENCE_PERCENTAGE;
        break;
    }


    case LONGITUDINAL_ACTION_NONE:
    default:
    {
        break;
    }
}


return speed_mps;
}

void get_user_input(float* speed_mps, uint32_t* lane_idx)
{
char de_acc = 0;
char right_left = 0;
scanf(" %c", &de_acc);
scanf(" %c", &right_left);
*lane_idx = handle_lateral_user_input(*lane_idx,right_left);
*speed_mps =  handle_longitudinal_user_input(*speed_mps,de_acc);


    return;
}
