#ifndef AD_TYPES_H
#define AD_TYPES_H

typedef enum LaneAssociationType
{
    LANE_ASSOCIATION_TYPE_NONE,
    LANE_ASSOCIATION_TYPE_LEFT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_RIGHT,
}LaneAssociationType_t;

typedef enum LongitudinalAction
{
    LONGITUDINAL_ACTION_INCREASE ='w',//Increase
    LONGITUDINAL_ACTION_DECREASE ='s',//Decreas
    LONGITUDINAL_ACTION_NONE,//NONE
}LongitudinalAction_t;

typedef enum LateraAction
{
LATERAL_ACTION_TYPE_LEFT = 'a',//Left
LATERAL_ACTION_TYPE_RIGTH = 'd',//Right
LATERAL_ACTION_TYPE_NONE,//NONE
}LateraAction_t;



#endif
