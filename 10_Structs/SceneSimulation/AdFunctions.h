#include <stdint.h>

#include "AdTypes.h"

void init_ego_vehicle(VehicleTypeego_vehicle);

void init_vehicles(NeighborVehiclesTypevehicles);

void print_vehicle(const VehicleType vehicle);

void print_neighbor_vehicles(const NeighborVehiclesTypevehicles);

void print_scene(const VehicleType ego_vehicle, const NeighborVehiclesTypevehicles);

void compute_future_distance(VehicleType vehicle, const float ego_driven_distance, const float seconds);

void compute_future_state(const VehicleType ego_vehicle, NeighborVehiclesTypevehicles, const float seconds);
