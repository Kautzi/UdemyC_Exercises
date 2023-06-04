#ifndef B0FE3F42_A192_48EB_BDD3_D7CBC35D8661
#define B0FE3F42_A192_48EB_BDD3_D7CBC35D8661
#ifndef ADDATALOADER_H
#define ADDATALOADER_H

#include "AdTypes.h"
#include <stdint.h>

void preload_ego_vehicle_data(const char datapath[128], int use_case_idx);

void preload_vehicle_data(const char datapath[128], int use_case_idx);

void init_ego_vehicle(VehicleType *ego_vehicle);

void init_vehicle(VehicleType *vehicle, const int32_t id, const uint32_t cycle);

void init_vehicles(NeighborVehiclesType *vehicles);

void load_cycle(NeighborVehiclesType *vehicles, const uint32_t cycle);

#endif // ADDATALOADER_H


#endif /* B0FE3F42_A192_48EB_BDD3_D7CBC35D8661 */
