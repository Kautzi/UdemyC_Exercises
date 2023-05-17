#ifndef B4E12BA5_12AA_4FAC_BA32_668864793624
#define B4E12BA5_12AA_4FAC_BA32_668864793624
#ifndef AD_TYPES_H
#define AD_TYPES_H

#include <stdint.h>
#include "AdConstants.h"

typedef enum
{
    LANE_ASSOCIATION_TYPE_NONE,
    LANE_ASSOCIATION_TYPE_LEFT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_RIGHT,
}LaneAssociationType;

typedef enum
{
    LONGITUDINAL_ACTION_NONE,
    LONGITUDINAL_ACTION_ACCELERATE = 'w',
    LONGITUDINAL_ACTION_DECELERATE = 's',
}LongitudinalAction;

typedef enum
{
    LATERAL_ACTION_NONE,
    LATERAL_ACTION_LEFT = 'a',
    LATERAL_ACTION_RIGHT = 'd',
}LateralAction;

typedef struct
{
int32_t Vehicle_ID;
LaneAssociationType lane;
float speed;
float distance_to_ego_ID;
}VehicleType;

typedef struct
{
VehicleType vehicles_left_lane [Vehicle_Array_Length];
VehicleType vehicles_center_lane [Vehicle_Array_Length];
VehicleType vehicles_right_lane [Vehicle_Array_Length];
}NeighborVehiclesType;

#endif


#endif /* B4E12BA5_12AA_4FAC_BA32_668864793624 */
