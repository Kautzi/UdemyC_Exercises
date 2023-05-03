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

float handle_longitudinal_user_input(float speed_mps,LongitudinalAction_t de_increase_none)
{

switch(de_increase_none)
{
    case w:
    {
        speed_mps +=speed_mps * LONGITUDINAL_DIFFERENCE_PERCENTAGE;
        break;
    }

    case s:
    {
        speed_mps -=speed_mps * LONGITUDINAL_DIFFERENCE_PERCENTAGE;
        break;
    }


    case q:
    default:
    {
        break;
    }
}


return speed_mps;
}

void get_user_input(float* speed_mps, uint32_t* lane_idx)
{
int de_acc = 0;
int right_left = 0;
scanf("%d", &de_acc);
scanf("%d", &right_left);
*lane_idx = handle_lateral_user_input(*lane_idx,right_left);
*speed_mps =  handle_longitudinal_user_input(*speed_mps,de_acc);


    return;
}
