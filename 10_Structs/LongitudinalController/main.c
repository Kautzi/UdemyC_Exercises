#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <threads.h>
#include <time.h>

#include "AdFunctions.h"
#include "AdTypes.h"

#include "utils.h"

int main()
{
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    init_ego_vehicle(ego_vehicle);
    init_vehicles(vehicles);

    print_vehicle(ego_vehicle);
    print_neighbor_vehicles(vehicles);

    printf("Start simulation?: ");
    char Input;
    scanf("%c", Input);

    while (true)
    {
        clear_console();

        print_scene(ego_vehicle, vehicles);
        compute_future_state(ego_vehicle, vehicles, 0.100F);
        longitudinal_control(vehicles.vehicles_center_lane[0], ego_vehicle);

        thrd_sleep(&(struct timespec){.tv_nsec = 100000}, NULL);
    }

    return 0;
}
