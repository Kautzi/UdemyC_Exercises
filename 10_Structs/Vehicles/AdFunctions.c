#include <stdio.h>
#include <string.h>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"

void print_scene(float speed_mps, uint32_t lane_idx)
{
    printf("\n\n    \t  L    C    R  \n");

    const float offset_m = 20;

    for (int32_t i = 100; i >= -100; i -= (int32_t)(offset_m))
    {
        char left_string[] = "   ";
        char center_string[] = "   ";
        char right_string[] = "   ";

        if (i == 0)
        {
            switch (lane_idx)
            {
            case LANE_ASSOCIATION_TYPE_LEFT:
            {
                strncpy(left_string, " V ", 4);
                break;
            }
            case LANE_ASSOCIATION_TYPE_CENTER:
            {
                strncpy(center_string, " V ", 4);

                break;
            }
            case LANE_ASSOCIATION_TYPE_RIGHT:
            {
                strncpy(left_string, " V ", 4);

                break;
            }
            default:
            {
                break;
            }
            }
        }
        printf("%d\t|%s|%s|%s|\n", i, left_string, center_string, right_string);
    }

    printf("\n");
    printf("Speed: %f\n", speed_mps);
    printf("\n");
}

void get_user_input(float *speed_mps, uint32_t *lane_idx)
{
    printf("\n");
    char longitudinal_action;
    printf("LongitudinalAction (w=Increase, s=Decrease): ");
    scanf(" %c", &longitudinal_action);
    printf("\n");
    char lateral_action;
    printf("LateralAction (a=Left, d=Right): ");
    scanf(" %c", &lateral_action);

    handle_lateral_user_inpur(lane_idx, lateral_action);
    handle_longitudinal_user_inpur(speed_mps, longitudinal_action);
}

void handle_lateral_user_inpur(uint32_t *lane_idx, char lateral_action)
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
        {
            return;
            break;
        }
        }
        break;
    }
    case LATERAL_ACTION_NONE:
    {
        return;
        break;
    }
    }
}

void handle_longitudinal_user_inpur(float *speed_mps, char longitudinal_action)
{
    switch (longitudinal_action)
    {
    case LONGITUDINAL_ACTION_ACCELERATE:
    {
        float new_speed = (*speed_mps) + ((*speed_mps) * LONGITUDINAL_DIFFERENCE_PERCENTAGE);
        *speed_mps = new_speed;
        break;
    }
    case LONGITUDINAL_ACTION_DECELERATE:
    {
        float new_speed = (*speed_mps) - ((*speed_mps) * LONGITUDINAL_DIFFERENCE_PERCENTAGE);
        *speed_mps = new_speed;
        break;
    }
    case LONGITUDINAL_ACTION_NONE:
    {
        return;
        break;
    }
    }
}

float kph_to_mps(const float kph)
{
    return kph / 3.6F;
}

void init_ego_vehicle(VehicleType *ego_vehicle)
{
    ego_vehicle->id = EGO_VEHICLE_ID;
    ego_vehicle->speed_mps = kph_to_mps(135.0F);
    ego_vehicle->distance_m = 0.0F;
    ego_vehicle->lane = LANE_ASSOCIATION_TYPE_CENTER;
}

void init_vehicle(VehicleType *vehicle,
                  const int32_t id,
                  const float speed_mps,
                  const float distance_m,
                  const LaneAssociationType lane)
{
    vehicle->id = id;
    vehicle->speed_mps = kph_to_mps(speed_mps);
    vehicle->distance_m = distance_m;
    vehicle->lane = lane;
}

void init_vehicles(NeighborVehiclesType *vehicles)
{
    init_vehicle(&vehicles->vehicles_left_lane[0], 0, 130.0F, 80.0F, LANE_ASSOCIATION_TYPE_LEFT);
    init_vehicle(&vehicles->vehicles_left_lane[1], 1, 80.0F, -20.0F, LANE_ASSOCIATION_TYPE_LEFT);
    init_vehicle(&vehicles->vehicles_center_lane[0], 2, 80.0F, 50.0F, LANE_ASSOCIATION_TYPE_CENTER);
    init_vehicle(&vehicles->vehicles_center_lane[1], 3, 120.0F, -50.0F, LANE_ASSOCIATION_TYPE_CENTER);
    init_vehicle(&vehicles->vehicles_right_lane[0], 4, 110.0F, 30.0F, LANE_ASSOCIATION_TYPE_RIGHT);
    init_vehicle(&vehicles->vehicles_right_lane[1], 5, 90.0F, -30.0F, LANE_ASSOCIATION_TYPE_RIGHT);
}

void print_vehicle(const VehicleType *vehicle)
{
    if (EGO_VEHICLE_ID == vehicle->id)
    {
        printf("Ego Vehicle: \n");
        printf("Speed (m/s): %f\n", vehicle->speed_mps);
    }
    else
    {
        printf("ID: %d\n", vehicle->id);
        printf("Speed (m/s): %f\n", vehicle->speed_mps);
        printf("Distance (m): %f\n", vehicle->distance_m);
    }
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
