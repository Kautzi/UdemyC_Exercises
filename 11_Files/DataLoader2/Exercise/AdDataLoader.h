#ifndef ADDATALOADER_H
#define ADDATALOADER_H

#include "AdTypes.h"
#include <stdint.h>

void preload_ego_vehicle_data(const char datapath[128]);

void preload_vehicle_data(const char datapath[128]);

void init_ego_vehicle(VehicleType *ego_vehicle);

void init_vehicle(VehicleType *vehicle, const int32_t id, const uint32_t cycle);

void init_vehicles(NeighborVehiclesType *vehicles);

void load_cycle(NeighborVehiclesType *vehicles, const uint32_t cycle);

#endif // ADDATALOADER_H
