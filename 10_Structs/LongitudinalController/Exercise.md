# Exercise

Update the following functions

```cpp
void print_scene(const VehicleType *const ego_vehicle, const NeighborVehiclesType *const vehicles);
```

- print_scene:
  - Update the distance slices to 10m instead of 20m
  - Add at the bottom of the function the speed of the ego vehicle

Implement the following functions:

```cpp
void longitudinal_control(const VehicleType *const front_vehicle, VehicleType *const ego_vehicle);
```

If there is a vehicle in front of the ego vehicle and the distance is below half speed (kph, "halbe tacho"), the vehicle needs to slow down (brake pedal).  
You can choose a value of the deceleration (braking).

## Main Function

```cpp
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "AdFunctions.h"
#include "AdTypes.h"

#include "utils.h"

int main()
{
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    init_ego_vehicle(&ego_vehicle);
    init_vehicles(&vehicles);

    print_vehicle(&ego_vehicle);
    print_neighbor_vehicles(&vehicles);

    printf("Start simulation?: ");
    char Input;
    scanf("%c", &Input);

    while (true)
    {
        clear_console();

        print_scene(&ego_vehicle, &vehicles);
        compute_future_state(&ego_vehicle, &vehicles, 0.100F);
        longitudinal_control(&vehicles.vehicles_center_lane[0], &ego_vehicle);

        sleep_console(100);
    }

    return 0;
}
```
