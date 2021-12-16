#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "AdFunctions.h"
#include "AdTypes.h"

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
        compute_future_state(ego_vehicle, vehicles, 0.050F);
        const LaneAssociationType lane_change_request = longitudinal_control(vehicles, ego_vehicle);
        const bool lane_change_successful = lateral_control(vehicles, lane_change_request, ego_vehicle);

        if (lane_change_request != ego_vehicle.lane)
        {
            printf("Lane change request: %d", (int)(lane_change_request));
        }
        if (lane_change_successful)
        {
            printf("Lane change successull");
        }

        this_thread::sleep_for(chrono::milliseconds(50));
    }

    return 0;
}
