# Exercise

Update the following functions

```cpp
void print_scene(const VehicleType ego_vehicle, const NeighborVehiclesTypevehicles);
```

- print_scene:
  - Update the distance slices to 10m instead of 20m
  - Add at the bottom of the function the speed of the ego vehicle

<img src="../../media/vehicle2.png" alt="vehicle"/>

Implement the following functions:

```cpp
void longitudinal_control(const VehicleType front_vehicle, VehicleType ego_vehicle);
```

If there is a vehicle in front of the ego vehicle and the distance is below half speed (kph, "halbe tacho"), the vehicle needs to slow down (brake pedal).  
You can choose a value of the deceleration (braking).

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
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    init_ego_vehicle(ego_vehicle);
    init_vehicles(vehicles);

    print_vehicle(ego_vehicle);
    print_neighbor_vehicles(vehicles);

    printf("Start simulation?: ";
    char Input;
    scanf("%d",Input;

    while (true)
    {
        clear_console();

        print_scene(ego_vehicle, vehicles);
        compute_future_state(ego_vehicle, vehicles, 0.100F);
        longitudinal_control(vehicles.vehicles_center_lane[0], ego_vehicle);

        THIS_THREAD_sleep_for(CHRONO_milliseconds(100));
    }

    return 0;
}
```
