#ifndef E06B6697_DBF3_45F7_BE0B_7BB42527949A
#define E06B6697_DBF3_45F7_BE0B_7BB42527949A
#ifndef CBEEEC82_8BDE_4048_9606_8E48C5A43653
#define CBEEEC82_8BDE_4048_9606_8E48C5A43653
#ifndef FEC7189C_1B0D_4805_AFB5_BB3D447F9CB3
#define FEC7189C_1B0D_4805_AFB5_BB3D447F9CB3
#ifndef C3B4FADE_BC70_46D0_806E_22D4C5B6D87D
#define C3B4FADE_BC70_46D0_806E_22D4C5B6D87D

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


#endif /* C3B4FADE_BC70_46D0_806E_22D4C5B6D87D */


#endif /* FEC7189C_1B0D_4805_AFB5_BB3D447F9CB3 */


#endif /* CBEEEC82_8BDE_4048_9606_8E48C5A43653 */


#endif /* E06B6697_DBF3_45F7_BE0B_7BB42527949A */
