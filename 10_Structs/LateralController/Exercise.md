# Exercise

Update the following functions:

```cpp
void print_scene(const VehicleType &ego_vehicle, const NeighborVehiclesType &vehicles);

LaneAssociationType longitudinal_control(const NeighborVehiclesType &vehicles,VehicleType &ego_vehicle);
```

- print_scene: Such that the ego vehicle can be displayed on every lane not only the center lane.
- longitudinal_control:
  - If we would crash with the front or rear vehicle, call the **get_lane_change_request** function.
  - We don't pass in the front/rear vehicle anymore, instead of the whole array.
    - Get the front/rear vehicle internally.

Implement the following functions:

```cpp
LaneAssociationType get_lane_change_request(const VehicleType &ego_vehicle,
                                            const float front_distance,
                                            const float rear_distance);

bool lateral_control(const NeighborVehiclesType &vehicles,
                     const LaneAssociationType lane_change_request,
                     VehicleType &ego_vehicle);
```

- get_lane_change_request:
  - Send a lane change request if the vehicle would crash into a front/rear vehicle
    - Send a request to the left, if we are too close to the front vehicle (hence we are faster)
    - Send a request to the right, if we are too close to the rear vehicle (hence we are slower)
  - Checks if we can change the lane onto the target lane that was sent from the **get_lane_change_request** function
  - Check the size of the gap on the target lane

## Main Function

```cpp
#include <chrono>
#include <string.h>
#include <stdio.h>
#include <numeric>
#include <thread>

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
            printf("Lane change request: " << (int)(lane_change_request) << endl;
        }
        if (lane_change_successful)
        {
            printf("Lane change successull" << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(50));
    }

    return 0;
}

```
