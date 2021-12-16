#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"
#include "DataLoader.h"

float kph_to_mps(const float kph)
{
    return kph / 3.6F;
}

float mps_to_kmh(const float mps)
{
    return mps * 3.6F;
}

void print_vehicle(const VehicleType *const vehicle)
{
    if (EGO_VEHICLE_ID == vehicle->id)
    {
        printf("Ego Vehicle: \n");
        printf("Speed (m/s): %f\n", vehicle->speed_mps);
    }
    else
    {
        printf("ID: %d\n", vehicle->id);
        printf("Speed (m/s): %f\n", vehicle->speed_mps);
        printf("Distance (m): %f\n", vehicle->distance_m);
    }
}

void print_neighbor_vehicles(const NeighborVehiclesType *const vehicles)
{
    print_vehicle(&vehicles->vehicles_left_lane[0]);
    print_vehicle(&vehicles->vehicles_left_lane[1]);
    print_vehicle(&vehicles->vehicles_center_lane[0]);
    print_vehicle(&vehicles->vehicles_center_lane[1]);
    print_vehicle(&vehicles->vehicles_right_lane[0]);
    print_vehicle(&vehicles->vehicles_right_lane[1]);
}

void print_scene(const VehicleType *const ego_vehicle, const NeighborVehiclesType *const vehicles)
{
    printf("\n\n    \t  L    C    R  \n");

    size_t left_idx = 0;
    size_t center_idx = 0;
    size_t right_idx = 0;

    const int32_t offset_m = 10;

    for (int32_t i = 100; i >= -100; i -= offset_m)
    {
        const VehicleType *const left_vehicle = &vehicles->vehicles_left_lane[left_idx];
        const VehicleType *const center_vehicle = &vehicles->vehicles_center_lane[center_idx];
        const VehicleType *const right_vehicle = &vehicles->vehicles_right_lane[right_idx];

        char left_string[] = "   ";
        char center_string[] = "   ";
        char right_string[] = "   ";
        char *ego_string = NULL;

        const float range_m = (float)(i);

        switch (ego_vehicle->lane)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            ego_string = left_string;
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            ego_string = center_string;
            break;
        }
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            ego_string = right_string;
            break;
        }
        default:
        {
            break;
        }
        }

        if ((ego_string != NULL) && (range_m >= ego_vehicle->distance_m) &&
            (ego_vehicle->distance_m > (range_m - offset_m)))
        {
            ego_string[1] = 'E';
        }

        if ((range_m >= left_vehicle->distance_m) && (left_vehicle->distance_m > (range_m - offset_m)))
        {
            left_string[1] = 'V';
            left_idx++;
        }

        if ((range_m >= center_vehicle->distance_m) && (center_vehicle->distance_m > (range_m - offset_m)))
        {
            center_string[1] = 'V';
            center_idx++;
        }

        if ((range_m >= right_vehicle->distance_m) && (right_vehicle->distance_m > (range_m - offset_m)))
        {
            right_string[1] = 'V';
            right_idx++;
        }

        printf("%d\t|%s|%s|%s|\n", i, left_string, center_string, right_string);
    }

    printf("\n");
    print_vehicle_speed(ego_vehicle, "E");
    printf("\n");
}

void print_vehicle_speed(const VehicleType *const vehicle, const char *name)
{
    printf("%s: (%f mps)", name, vehicle->speed_mps);
}

void compute_future_distance(VehicleType *const vehicle, const float ego_driven_distance, const float seconds)
{
    const float driven_distance = vehicle->speed_mps * seconds;
    vehicle->distance_m += driven_distance - ego_driven_distance;
}

void compute_future_state(const VehicleType *const ego_vehicle,
                          NeighborVehiclesType *const vehicles,
                          const float seconds)
{
    const float ego_driven_distance = ego_vehicle->speed_mps * seconds;

    compute_future_distance(&vehicles->vehicles_left_lane[0], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_left_lane[1], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_center_lane[0], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_center_lane[1], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_right_lane[0], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_right_lane[1], ego_driven_distance, seconds);
}

void decrease_speed(VehicleType *const ego_vehicle)
{
    const float decrease = ego_vehicle->speed_mps * SPEED_ADAPTAION_FACTOR;

    if (ego_vehicle->speed_mps - decrease > 0.0F)
    {
        ego_vehicle->speed_mps -= decrease;
    }
}

const VehicleType *get_vehicle_array(const LaneAssociationType lane, const NeighborVehiclesType *const vehicles)
{
    const VehicleType *vehicles_array = NULL;

    switch (lane)
    {
    case LANE_ASSOCIATION_TYPE_LEFT:
    {
        vehicles_array = vehicles->vehicles_left_lane;
        break;
    }
    case LANE_ASSOCIATION_TYPE_CENTER:
    {
        vehicles_array = vehicles->vehicles_center_lane;
        break;
    }
    case LANE_ASSOCIATION_TYPE_RIGHT:
    {
        vehicles_array = vehicles->vehicles_right_lane;
        break;
    }
    default:
    {
        break;
    }
    }

    return vehicles_array;
}

LaneAssociationType longitudinal_control(const NeighborVehiclesType *const vehicles, VehicleType *const ego_vehicle)
{
    const VehicleType *vehicles_array = get_vehicle_array(ego_vehicle->lane, vehicles);

    if (vehicles_array == NULL)
    {
        return ego_vehicle->lane;
    }

    const VehicleType *const front_vehicle = &vehicles_array[0];
    const VehicleType *const rear_vehicle = &vehicles_array[1];

    const float minimal_distance = mps_to_kmh(ego_vehicle->speed_mps) / 2.0F;
    const float crash_distance = mps_to_kmh(ego_vehicle->speed_mps) / 4.0F;

    const float front_distance = front_vehicle->distance_m;
    const float rear_distance = fabs(rear_vehicle->distance_m);

    bool front_vehicle_too_close = false;

    bool front_vehicle_very_close = false;
    bool rear_vehicle_very_close = false;

    if (front_distance < minimal_distance)
    {
        front_vehicle_too_close = true;
    }

    if (front_distance < crash_distance)
    {
        front_vehicle_very_close = true;
    }

    if (rear_distance < crash_distance)
    {
        rear_vehicle_very_close = true;
    }

    if (front_vehicle_too_close)
    {
        decrease_speed(ego_vehicle);
    }

    if (front_vehicle_very_close || rear_vehicle_very_close)
    {
        return get_lane_change_request(ego_vehicle, front_distance, rear_distance);
    }

    return ego_vehicle->lane;
}

LaneAssociationType get_lane_change_request(const VehicleType *const ego_vehicle,
                                            const float front_distance,
                                            const float rear_distance)
{
    const bool left_lane_change = (front_distance < rear_distance);

    if (left_lane_change)
    {
        switch (ego_vehicle->lane)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            return ego_vehicle->lane;
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            return LANE_ASSOCIATION_TYPE_LEFT;
            break;
        }
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            return LANE_ASSOCIATION_TYPE_CENTER;
            break;
        }
        default:
        {
            return ego_vehicle->lane;
            break;
        }
        }
    }
    else
    {
        switch (ego_vehicle->lane)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            return LANE_ASSOCIATION_TYPE_CENTER;
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            return LANE_ASSOCIATION_TYPE_RIGHT;
            break;
        }
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            return ego_vehicle->lane;
            break;
        }
        default:
        {
            return ego_vehicle->lane;
            break;
        }
        }
    }
}

bool gap_is_valid(const VehicleType *const front_vehicle,
                  const VehicleType *const rear_vehicle,
                  const VehicleType *const ego_vehicle)
{
    const float minimal_distance = mps_to_kmh(ego_vehicle->speed_mps) / 5.0F;

    const float front_distance = front_vehicle->distance_m;
    const float rear_distance = fabs(rear_vehicle->distance_m);

    if ((front_distance > minimal_distance) && (rear_distance > minimal_distance))
    {
        return true;
    }

    return false;
}

bool lateral_control(const NeighborVehiclesType *const vehicles,
                     const LaneAssociationType lane_change_request,
                     VehicleType *const ego_vehicle)
{
    if (lane_change_request == ego_vehicle->lane)
    {
        return false;
    }

    const VehicleType *vehicles_array = get_vehicle_array(lane_change_request, vehicles);

    if (vehicles_array == NULL)
    {
        return false;
    }

    const bool valid = gap_is_valid(&vehicles_array[0], &vehicles_array[1], ego_vehicle);

    if (valid)
    {
        ego_vehicle->lane = lane_change_request;

        return true;
    }

    return false;
}
