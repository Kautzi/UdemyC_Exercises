#include <stdint.h>
#include <stdio.h>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"

void print_scene(float speed_mps, uint32_t lane_idx)
{
    int32_t lane_count = 100;// this Varable counts the lanes in front and behind the actual lane of the vehicle

    printf("\n\n");
    printf("\t  L   C   R\n");
    while(lane_count >= -100)
    {
    if(lane_count == 0)
    {
        switch (lane_idx)
    {
    case LANE_ASSOCIATION_TYPE_LEFT:
    {
        printf("%d\t| V |   |   |\n",lane_count);
        break;
    }
    case LANE_ASSOCIATION_TYPE_CENTER:
    {
        printf("%d\t|   | V |   |\n",lane_count);
        break;
    }
    case LANE_ASSOCIATION_TYPE_RIGHT:
    {
        printf("%d\t|   |   | V |\n",lane_count);
        break;
    }
    case LANE_ASSOCIATION_TYPE_NONE:
    default:
    {
        printf("%d\t|   |   |   |\n",lane_count);
        break;
    }
    }
    lane_count-=20;
    }
    else
    {
    printf("%d\t|   |   |   |\n",lane_count);
    }
    lane_count-=20;
    }

        printf("\n");
        printf("Speed: %f\n", speed_mps);
        printf("\n");
}

void get_user_input(float *speed_mps, uint32_t *lane_idx)
{
    printf("\n");

    char long_action;
    printf("LongAction (w=Increase, s=Decrease): ");
    scanf(" %c", &long_action);
    handle_longitudinal_user_input(speed_mps, long_action);

    char lat_action;
    printf("LateralAction (a=Left, d=Right): ");
    scanf(" %c", &lat_action);
    handle_lateral_user_input(lane_idx, lat_action);
}

void handle_lateral_user_input(uint32_t *lane_idx, char lateral_action)
{
    switch (lateral_action)
    {
    case LATERAL_ACTION_LEFT:
    {
        switch (*lane_idx)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            return;
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            *lane_idx = LANE_ASSOCIATION_TYPE_LEFT;
            break;
        }
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            *lane_idx = LANE_ASSOCIATION_TYPE_CENTER;
            break;
        }
        case LANE_ASSOCIATION_TYPE_NONE:
        default:
        {
            return;
            break;
        }
        }
        break;
    }
    case LATERAL_ACTION_RIGHT:
    {
        switch (*lane_idx)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            *lane_idx = LANE_ASSOCIATION_TYPE_CENTER;
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            *lane_idx = LANE_ASSOCIATION_TYPE_RIGHT;
            break;
        }
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            return;
            break;
        }
        case LANE_ASSOCIATION_TYPE_NONE:
        default:
        {
            return;
            break;
        }
        }
        break;
    }
    case LATERAL_ACTION_NONE:
    default:
    {
        break;
    }
    }
}

void handle_longitudinal_user_input(float *speed_mps, char long_action)
{
    switch (long_action)
    {
    case LONGITUDINAL_ACTION_ACCELERATE:
    {
        float new_speed =
            (*speed_mps) + ((*speed_mps) * LONGITUDINAL_DIFFERENCE_PERCENTAGE);
        *speed_mps = new_speed;
        break;
    }
    case LONGITUDINAL_ACTION_DECELERATE:
    {
        float new_speed =
            (*speed_mps) - ((*speed_mps) * LONGITUDINAL_DIFFERENCE_PERCENTAGE);
        *speed_mps = new_speed;
        break;
    }
    case LONGITUDINAL_ACTION_NONE:
    default:
    {
        break;
    }
    }
}
