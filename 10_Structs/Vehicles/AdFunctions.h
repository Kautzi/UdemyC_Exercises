#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdint.h>

#include "AdTypes.h"

void init_ego_vehicle(VehicleType *const ego_vehicle);

void init_vehicles(NeighborVehiclesType *const vehicles);

void print_vehicle(const VehicleType *const vehicle);

void print_neighbor_vehicles(const NeighborVehiclesType *const vehicles);

void print_scene(const VehicleType *const ego_vehicle, const NeighborVehiclesType *const vehicles);

void compute_future_distance(VehicleType *const vehicle, const float ego_driven_distance, const float seconds);

void compute_future_state(const VehicleType *const ego_vehicle,
                          NeighborVehiclesType *const vehicles,
                          const float seconds);

#endif
