#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdint.h>

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

void print_scene(float speed_mps, float pos_m, uint32_t lane_idx);

void get_user_input(float *speed_mps, uint32_t *lane_idx);

void handle_lateral_user_inpur(uint32_t *lane_idx, char lateral_action);

void handle_longitudinal_user_inpur(float *speed_mps, char longitudinal_action);

#endif
