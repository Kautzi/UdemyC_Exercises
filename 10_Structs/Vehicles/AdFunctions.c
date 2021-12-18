#include <stdio.h>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"

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

void print_scene(const VehicleType *ego_vehicle, const NeighborVehiclesType *vehicles)
{
    printf("\n\n    \t  L    C    R  \n");

    size_t left_idx = 0;
    size_t center_idx = 0;
    size_t right_idx = 0;

    const float offset_m = 20;

    for (int32_t i = 100; i >= -100; i -= (int32_t)(offset_m))
    {
        const VehicleType *left_vehicle = &vehicles->vehicles_left_lane[left_idx];
        const VehicleType *center_vehicle = &vehicles->vehicles_center_lane[center_idx];
        const VehicleType *right_vehicle = &vehicles->vehicles_right_lane[right_idx];

        char left_string[] = "   ";
        char center_string[] = "   ";
        char right_string[] = "   ";

        const float range_m = (float)(i);

        if ((range_m >= left_vehicle->distance_m) && (left_vehicle->distance_m > (range_m - offset_m)))
        {
            left_string[1] = 'V';
            left_idx++;
        }

        if ((range_m >= ego_vehicle->distance_m) && (ego_vehicle->distance_m > (range_m - offset_m)))
        {
            center_string[1] = 'E';
        }
        else if ((range_m >= center_vehicle->distance_m) && (center_vehicle->distance_m > (range_m - offset_m)))
        {
            center_string[1] = 'V';
            center_idx++;
        }

        if ((range_m >= right_vehicle->distance_m) && (right_vehicle->distance_m > (range_m - offset_m)))
        {
            right_string[1] = 'V';
            right_idx++;
        }

        printf("%d\t|%s|%s|%s|\n", i, left_string, center_string, right_string);
    }

    printf("\n");
}

void compute_future_distance(VehicleType *vehicle, const float ego_driven_distance, const float seconds)
{
    const float driven_distance = vehicle->speed_mps * seconds;
    vehicle->distance_m += driven_distance - ego_driven_distance;
}

void compute_future_state(const VehicleType *ego_vehicle, NeighborVehiclesType *vehicles, const float seconds)
{
    const float ego_driven_distance = ego_vehicle->speed_mps * seconds;

    compute_future_distance(&vehicles->vehicles_left_lane[0], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_left_lane[1], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_center_lane[0], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_center_lane[1], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_right_lane[0], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_right_lane[1], ego_driven_distance, seconds);
}
