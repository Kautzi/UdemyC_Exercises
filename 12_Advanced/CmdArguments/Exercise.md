# Exercise

Implement the following functions:

```cpp
...
```

- ...
  - ...

## Main Function

```cpp
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AdFunctions.h"
#include "AdTypes.h"
#include "DataLoader.h"

#include "utils.h"

char datapath[128] = "C:/Users/Jan/Dropbox/_Coding/UdemyCExt/12_Advanced/CmdArguments/data/";

int main(int argc, char const **argv)
{
    int use_case_idx = 0;

    if (argc >= 2)
    {
        strncpy(datapath, argv[1], 128);
    }

    if (argc == 3)
    {
        use_case_idx = atoi(argv[2]);
    }

    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    preload_ego_vehicle_data(datapath, use_case_idx);
    preload_vehicle_data(datapath, use_case_idx);

    init_ego_vehicle(&ego_vehicle);
    init_vehicles(&vehicles);

    print_vehicle(&ego_vehicle);
    print_neighbor_vehicles(&vehicles);

    printf("Start simulation?: ");
    char Input;
    scanf("%c", &Input);

    for (uint32_t cycle = 0; cycle < NUM_CYCLES; cycle++)
    {
        clear_console();

        load_cycle(&vehicles, cycle);
        print_scene(&ego_vehicle, &vehicles);
        compute_future_state(&ego_vehicle, &vehicles, 0.100F);
        const LaneAssociationType lane_change_request = longitudinal_control(&vehicles, &ego_vehicle);
        const bool lane_change_successful = lateral_control(&vehicles, lane_change_request, &ego_vehicle);

        if (lane_change_request != ego_vehicle.lane)
        {
            printf("Lane change request: %d", (int)(lane_change_request));
        }
        if (lane_change_successful)
        {
            printf("Lane change successull");
        }

        sleep_console(100);
    }

    return 0;
}
```
