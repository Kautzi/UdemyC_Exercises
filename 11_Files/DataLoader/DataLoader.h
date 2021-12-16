#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <stdint.h>

#include "AdTypes.h"

#define NUM_VEHICLES 6
#define NUM_ITERATIONS 1000

void init_ego_vehicle(VehicleType *const ego_vehicle);

void init_vehicle(VehicleType *const vehicle,
                  const int32_t id,
                  const float speed_mps,
                  const float distance_m,
                  const LaneAssociationType lane);

void init_vehicles(NeighborVehiclesType *const vehicles);

#endif
