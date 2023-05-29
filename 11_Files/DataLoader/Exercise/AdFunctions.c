#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

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

    float offset_m = 10.0f;

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

float mps_to_kph(const float mps)
{
    return mps * 3.6f;
}

void decrease_speed(VehicleType *ego_vehicle)
{
const float decrease_speed = ego_vehicle->speed * LONGITUDINAL_DIFFERENCE_PERCENTAGE;

if((ego_vehicle->speed - decrease_speed) > 0)
{
    ego_vehicle->speed -= decrease_speed;
}

}

void longitudinal_control(const VehicleType* front_vehicle, VehicleType *ego_vehicle)
{

const float min_distance = mps_to_kph(ego_vehicle->speed)/2.0f;
const float front_distance = front_vehicle->distance_to_ego_ID;

if(front_distance < min_distance)
{
    decrease_speed(ego_vehicle);
}


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

void compute_future_distance(VehicleType * vehicle,
                             const float ego_driven_distance,
                             const float seconds)
{

const float driven_distance = vehicle->speed * seconds;

vehicle->distance_to_ego_ID = vehicle->distance_to_ego_ID + ( driven_distance - ego_driven_distance);

}

void compute_future_state(const VehicleType * ego_vehicle,
                          NeighborVehiclesType * vehicles,
                          const float seconds)
{
const float ego_driven_distance = ego_vehicle->speed * seconds;

for(size_t i = 0; i <= Vehicle_Array_Length; i++)
{
    compute_future_distance(&vehicles->vehicles_left_lane[i],ego_driven_distance,seconds);
    compute_future_distance(&vehicles->vehicles_center_lane[i],ego_driven_distance,seconds);
    compute_future_distance(&vehicles->vehicles_right_lane[i],ego_driven_distance,seconds);
}
}

const VehicleType *get_vehicle_array(const LaneAssociationType ego_lane,
                                     const NeighborVehiclesType *vehicles)
{
    /*
    LANE_ASSOCIATION_TYPE_NONE,
    LANE_ASSOCIATION_TYPE_LEFT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_RIGHT,*/
    switch(ego_lane)
    {

        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            return vehicles->vehicles_left_lane;
            break;
        }

        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            return vehicles->vehicles_center_lane;
            break;
        }

        case LANE_ASSOCIATION_TYPE_RIGHT:
        {

            break;
        }


        //both if none ore else set default and break
        case LANE_ASSOCIATION_TYPE_NONE:
        default:
        {
        return NULL;
        break;
        }
    }
return NULL;
}

LaneAssociationType get_lane_change_request(const VehicleType *ego_vehicle,
                                            const NeighborVehiclesType  *vehicles)
{
const VehicleType * same_lane_vehicle = get_vehicle_array(ego_vehicle->lane,vehicles);
const VehicleType * rear_vehicle = &same_lane_vehicle[1];

const float min_distance = mps_to_kph(ego_vehicle->speed)/2.0f;
const float rear_distance = (float)fabs(rear_vehicle->distance_to_ego_ID);

if(rear_distance < min_distance)
{
    switch(ego_vehicle->lane)
    {
       case LANE_ASSOCIATION_TYPE_LEFT:
       case LANE_ASSOCIATION_TYPE_RIGHT:
       {
        const VehicleType * center_lane_vehicles = get_vehicle_array(LANE_ASSOCIATION_TYPE_CENTER,vehicles);
        const float front_center_distance = (float)fabs(center_lane_vehicles[0].distance_to_ego_ID);
        const float rear_center_distance = (float)fabs(center_lane_vehicles[1].distance_to_ego_ID);

        if(front_center_distance > min_distance && rear_center_distance > min_distance )
        {
            return LANE_ASSOCIATION_TYPE_CENTER;
        }

        break;
       }

       case LANE_ASSOCIATION_TYPE_CENTER:
       {
        const VehicleType * left_lane_vehicles = get_vehicle_array(LANE_ASSOCIATION_TYPE_LEFT,vehicles);
        const float front_left_distance = (float)fabs(left_lane_vehicles[0].distance_to_ego_ID);
        const float rear_left_distance = (float)fabs(left_lane_vehicles[1].distance_to_ego_ID);

        const VehicleType * right_lane_vehicles = get_vehicle_array(LANE_ASSOCIATION_TYPE_RIGHT,vehicles);
        const float front_right_distance = (float)fabs(right_lane_vehicles[0].distance_to_ego_ID);
        const float rear_right_distance = (float)fabs(right_lane_vehicles[1].distance_to_ego_ID);

        if(front_right_distance > min_distance && rear_right_distance > min_distance )
        {
            return LANE_ASSOCIATION_TYPE_RIGHT;
        }

        if(front_left_distance > min_distance && rear_left_distance > min_distance )
        {
            return LANE_ASSOCIATION_TYPE_LEFT;
        }



        break;
       }

       case LANE_ASSOCIATION_TYPE_NONE:
       default:
       {
        return LANE_ASSOCIATION_TYPE_NONE;
        break;
       }


    }

}


return ego_vehicle->lane;
}

bool lateral_control(
                     const LaneAssociationType lane_change_request,
                     VehicleType *ego_vehicle)
{

if(lane_change_request == ego_vehicle->lane)
{
return false;
}

ego_vehicle->lane = lane_change_request;
return true;

}
