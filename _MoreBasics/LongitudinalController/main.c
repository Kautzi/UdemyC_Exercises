#include <chrono>
#include <numeric>
#include <stdio.h>
#include <string.h>
#include <thread>

#include "AdFunctions.hpp"
#include "AdTypes.hpp"

#include "utils.h"

int main()
{
    VehicleType ego_vehicle{};
    NeighborVehiclesType vehicles{};

    init_ego_vehicle(ego_vehicle);
    init_vehicles(vehicles);

    print_vehicle(ego_vehicle);
    print_neighbor_vehicles(vehicles);

    printf("Start simulation?: ";
    char Input;
    scanf("%d", &Input;

    while (true)
    {
        clear_console();

        print_scene(ego_vehicle, vehicles);
        compute_future_state(ego_vehicle, vehicles, 0.100F);
        longitudinal_control(vehicles.vehicles_center_lane[0], ego_vehicle);

        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}
