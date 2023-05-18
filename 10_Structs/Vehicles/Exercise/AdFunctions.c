#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"

void print_scene(float speed_mps, uint32_t lane_idx)
{

    printf("\n\n");
    printf("\t  L   C   R\n");

    float offset_m = 20.0f;

    for(int32_t i = 100; i >= -100; i -= (int32_t)(offset_m))
    {
        char left_string[]="   ";
        char center_string[]="   ";
        char right_string[]="   ";

    if(i == 0)
    {
        switch (lane_idx)
    {
    case LANE_ASSOCIATION_TYPE_LEFT:
    {
        strncpy(left_string," V ",4);
        break;
    }
    case LANE_ASSOCIATION_TYPE_CENTER:
    {
        strncpy(center_string," V ",4);;
        break;
    }
    case LANE_ASSOCIATION_TYPE_RIGHT:
    {
        strncpy(right_string," V ",4);;
        break;
    }
    case LANE_ASSOCIATION_TYPE_NONE:
    default:
    {

        break;
    }
    }

    }

    printf("%d\t|%s|%s|%s|\n",i,left_string,center_string,right_string);

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

float kph_to_mps(float kph)
{
    return kph / 3.6f;
}

void init_ego_vehicle(VehicleType *ego_vehicle)
{
    if(ego_vehicle == NULL)
    {
        return;
    }
    ego_vehicle->Vehicle_ID= EGO_ID;
    ego_vehicle->distance_to_ego_ID=0;
    printf("Enter the initil Speed of Ego Vehicle >= 20 <= 50:\n");
    scanf("%f",&ego_vehicle->speed);
    printf("Enter the lane on which the Ego Vehicle is on 1= left 2= center 3= right:\n");
    scanf("%u",&ego_vehicle->lane);


}

void init_vehicle(VehicleType * vehicle,int32_t id, float speed_mps, float distance, LaneAssociationType lane)
{
    vehicle->Vehicle_ID=id;
    vehicle->distance_to_ego_ID= distance;
    vehicle->speed=kph_to_mps(speed_mps);
    vehicle->lane=lane;
}

void init_vehicles(NeighborVehiclesType *vehicles)
{
    init_vehicle(&vehicles->vehicles_left_lane[0],0,130.0f,80.0f,LANE_ASSOCIATION_TYPE_LEFT);
    init_vehicle(&vehicles->vehicles_left_lane[1],1,50.0f,-60.0f,LANE_ASSOCIATION_TYPE_LEFT);

    init_vehicle(&vehicles->vehicles_center_lane[0],2,90.0f,-10.0f,LANE_ASSOCIATION_TYPE_CENTER);
    init_vehicle(&vehicles->vehicles_center_lane[1],3,55.0f,30.0f,LANE_ASSOCIATION_TYPE_CENTER);

    init_vehicle(&vehicles->vehicles_right_lane[0],4,160.0f,-10.0f,LANE_ASSOCIATION_TYPE_RIGHT);
    init_vehicle(&vehicles->vehicles_right_lane[1],5,20.0f,-90.0f,LANE_ASSOCIATION_TYPE_RIGHT);

}
void print_vehicle(const VehicleType *vehicle)
{
    printf("ID: %d\n",vehicle->Vehicle_ID);
    printf("Speed (m/s): %f\n",vehicle->speed);
    printf("Distance (m): %f\n",vehicle->distance_to_ego_ID);
    printf("Lane: %u\n",vehicle->lane);

}

void print_neighbor_vehicles(const NeighborVehiclesType *vehicles)
{

    print_vehicle(&vehicles->vehicles_left_lane[0]);
    print_vehicle(&vehicles->vehicles_left_lane[1]);
    print_vehicle(&vehicles->vehicles_center_lane[0]);
    print_vehicle(&vehicles->vehicles_center_lane[1]);
    print_vehicle(&vehicles->vehicles_right_lane[0]);
    print_vehicle(&vehicles->vehicles_right_lane[1]);

}
