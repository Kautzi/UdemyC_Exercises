#include <stdio.h>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"
#include "DataLoader.h"

void init_ego_vehicle(VehicleType *const ego_vehicle)
{
    ego_vehicle->id = EGO_VEHICLE_ID;
    ego_vehicle->speed_mps = kph_to_mps(135.0F);
    ego_vehicle->distance_m = 0.0F;
    ego_vehicle->lane = LANE_ASSOCIATION_TYPE_CENTER;
}

void init_vehicle(VehicleType *const vehicle,
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

void init_vehicles(NeighborVehiclesType *const vehicles)
{
    init_vehicle(&vehicles->vehicles_left_lane[0], 0, 130.0F, 80.0F, LANE_ASSOCIATION_TYPE_LEFT);
    init_vehicle(&vehicles->vehicles_left_lane[1], 1, 80.0F, -20.0F, LANE_ASSOCIATION_TYPE_LEFT);
    init_vehicle(&vehicles->vehicles_center_lane[0], 2, 80.0F, 50.0F, LANE_ASSOCIATION_TYPE_CENTER);
    init_vehicle(&vehicles->vehicles_center_lane[1], 3, 120.0F, -50.0F, LANE_ASSOCIATION_TYPE_CENTER);
    init_vehicle(&vehicles->vehicles_right_lane[0], 4, 110.0F, 30.0F, LANE_ASSOCIATION_TYPE_RIGHT);
    init_vehicle(&vehicles->vehicles_right_lane[1], 5, 90.0F, -30.0F, LANE_ASSOCIATION_TYPE_RIGHT);
}
