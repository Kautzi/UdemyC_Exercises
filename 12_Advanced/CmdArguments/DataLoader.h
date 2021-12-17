#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <stdint.h>

#include "AdConstants.h"
#include "AdTypes.h"

void preload_ego_vehicle_data(const char datapath[128], int use_case_idx);

void preload_vehicle_data(const char datapath[128], int use_case_idx);

void init_ego_vehicle(VehicleType *const ego_vehicle);

void init_vehicle(VehicleType *const vehicle, const int32_t id, const uint32_t cycle);

void init_vehicles(NeighborVehiclesType *const vehicles);

void load_cycle(NeighborVehiclesType *const vehicles, const uint32_t cycle);

#endif
