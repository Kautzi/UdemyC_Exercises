#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdint.h>

#include "AdTypes.h"

void init_ego_vehicle(VehicleType *const ego_vehicle);

void init_vehicles(NeighborVehiclesType *const vehicles);

void print_vehicle(const VehicleType *const vehicle);

void print_neighbor_vehicles(const NeighborVehiclesType *const vehicles);

#endif
