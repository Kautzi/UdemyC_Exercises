#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"

void print_scene(const VehicleType * ego_vehicle, const NeighborVehiclesType * vehicle)
{

    printf("\n\n");
    printf("\t  L   C   R\n");

    size_t left_idx=0;
    size_t center_idx=0;
    size_t right_idx=0;

    float offset_m = 20.0f;

    for(int32_t i = 100; i >= -100; i -= (int32_t)(offset_m))
    {

        const VehicleType *left_vehicle = (left_idx == Vehicle_Array_Length) ? NULL: &vehicle->vehicles_left_lane[left_idx];
        const VehicleType *center_vehicle =(center_idx == Vehicle_Array_Length) ? NULL: &vehicle->vehicles_center_lane[center_idx];
        const VehicleType *right_vehicle =(right_idx == Vehicle_Array_Length) ? NULL: &vehicle->vehicles_right_lane[right_idx];

        char left_string[]="   ";
        char center_string[]="   ";
        char right_string[]="   ";

        const float range_m= (float)(i);

        if((left_vehicle != NULL)&&(range_m >= left_vehicle->distance_to_ego_ID) && (left_vehicle->distance_to_ego_ID > (range_m - offset_m)))
        {
            strncpy(left_string," V ",4);
            left_idx++;
        }

        if((center_vehicle != NULL)&&(range_m >= center_vehicle->distance_to_ego_ID) && (center_vehicle->distance_to_ego_ID > (range_m - offset_m)))
        {
            strncpy(center_string," V ",4);
            center_idx++;
        }

        if((right_vehicle != NULL)&&(range_m >= right_vehicle->distance_to_ego_ID) && (right_vehicle->distance_to_ego_ID > (range_m - offset_m)))
        {
            strncpy(right_string," V ",4);
            right_idx++;
        }

    if(i == 0)
    {
        switch (ego_vehicle->lane)
    {
    case LANE_ASSOCIATION_TYPE_LEFT:
    {
        strncpy(left_string," E ",4);
        break;
    }
    case LANE_ASSOCIATION_TYPE_CENTER:
    {
        strncpy(center_string," E ",4);;
        break;
    }
    case LANE_ASSOCIATION_TYPE_RIGHT:
    {
        strncpy(right_string," E ",4);;
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
        printf("Speed: %f\n", ego_vehicle->speed);
        printf("\n");
}


float kph_to_mps(const float kph)
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

void init_vehicle(VehicleType * vehicle,const int32_t id,const float distance,const float speed_mps,const LaneAssociationType lane)
{
    vehicle->Vehicle_ID=id;
    vehicle->distance_to_ego_ID= distance;
    vehicle->speed=kph_to_mps(speed_mps);
    vehicle->lane=lane;
}

void init_vehicles(NeighborVehiclesType *vehicles)
{
    init_vehicle(&vehicles->vehicles_left_lane[0],0,100.0f,80.0f,LANE_ASSOCIATION_TYPE_LEFT);
    init_vehicle(&vehicles->vehicles_left_lane[1],1,-100.0f,60.0f,LANE_ASSOCIATION_TYPE_LEFT);

    init_vehicle(&vehicles->vehicles_center_lane[0],2,40.0f,10.0f,LANE_ASSOCIATION_TYPE_CENTER);
    init_vehicle(&vehicles->vehicles_center_lane[1],3,-60.0f,30.0f,LANE_ASSOCIATION_TYPE_CENTER);

    init_vehicle(&vehicles->vehicles_right_lane[0],4,80.0f,10.0f,LANE_ASSOCIATION_TYPE_RIGHT);
    init_vehicle(&vehicles->vehicles_right_lane[1],5,-20.0f,90.0f,LANE_ASSOCIATION_TYPE_RIGHT);

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
