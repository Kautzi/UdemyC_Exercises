#ifndef B4E12BA5_12AA_4FAC_BA32_668864793624
#define B4E12BA5_12AA_4FAC_BA32_668864793624
#ifndef AD_TYPES_H
#define AD_TYPES_H

enum LaneAssociationType
{
    LANE_ASSOCIATION_TYPE_NONE,
    LANE_ASSOCIATION_TYPE_LEFT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_RIGHT,
};

enum LongitudinalAction
{
    LONGITUDINAL_ACTION_NONE,
    LONGITUDINAL_ACTION_ACCELERATE = 'w',
    LONGITUDINAL_ACTION_DECELERATE = 's',
};

enum LateralAction
{
    LATERAL_ACTION_NONE,
    LATERAL_ACTION_LEFT = 'a',
    LATERAL_ACTION_RIGHT = 'd',
};

typedef struct Vehicle
{
int Vehicle_ID;
enum LANE_ASSOCIATION_TYPE_CENTER lane_association;
float speed;
float distance_to_ego_ID;
}VehicleType;

typedef struct NeighborsVehicle
{
//VehicleType[]
}NeighborVehiclesType;

#endif


#endif /* B4E12BA5_12AA_4FAC_BA32_668864793624 */
