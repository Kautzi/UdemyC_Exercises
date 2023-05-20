#ifndef DCF80A23_F86E_488B_9400_2F0CB8BAC420
#define DCF80A23_F86E_488B_9400_2F0CB8BAC420
#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdint.h>

#include "AdTypes.h"

void print_scene(const VehicleType * ego_vehicle, const NeighborVehiclesType * vehicle);

float kph_to_mps(const float kph);

void init_ego_vehicle(VehicleType *ego_vehicle);

void init_vehicles(NeighborVehiclesType *vehicles);

void init_vehicle(VehicleType * vehicle,const int32_t id,const float speed_mps,const float distance,const LaneAssociationType lane);

void print_vehicle(const VehicleType *vehicle);

void print_neighbor_vehicles(const NeighborVehiclesType *vehicles);
#endif


#endif /* DCF80A23_F86E_488B_9400_2F0CB8BAC420 */
