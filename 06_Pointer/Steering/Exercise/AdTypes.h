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
    w,//Increase
    s,//Decreas
    q,//NONE
}LongitudinalAction_t;

typedef enum LateraAction
{
a,//Left
d,//Right
c,//NONE
}LateraAction_t;



#endif
