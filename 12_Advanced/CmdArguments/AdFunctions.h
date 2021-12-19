#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdbool.h>
#include <stdint.h>

#include "AdTypes.h"

float kph_to_mps(const float kph);

float mps_to_kmh(const float mps);

void print_vehicle(const VehicleType *const vehicle);

void print_neighbor_vehicles(const NeighborVehiclesType *const vehicles);

void print_scene(const VehicleType *const ego_vehicle, const NeighborVehiclesType *const vehicles);

void print_vehicle_speed(const VehicleType *const vehicle, const char *name);

void compute_future_distance(VehicleType *const vehicle,
                             const float ego_driven_distance,
                             const float seconds);

void compute_future_state(const VehicleType *const ego_vehicle,
                          NeighborVehiclesType *const vehicles,
                          const float seconds);

const VehicleType *get_lane_vehicles(const LaneAssociationType lane,
                                     const NeighborVehiclesType vehicles);

LaneAssociationType longitudinal_control(const NeighborVehiclesType *const vehicles,
                                         VehicleType *const ego_vehicle);

LaneAssociationType get_lane_change_request(const VehicleType *const ego_vehicle,
                                            const float front_distance,
                                            const float rear_distance);

bool gap_is_valid(const VehicleType *const front_vehicle,
                  const VehicleType *const rear_vehicle,
                  const VehicleType *const ego_vehicle);

bool lateral_control(const NeighborVehiclesType *const vehicles,
                     const LaneAssociationType lane_change_request,
                     VehicleType *const ego_vehicle);

#endif
