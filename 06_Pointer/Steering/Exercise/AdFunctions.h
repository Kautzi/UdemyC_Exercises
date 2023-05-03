#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdint.h>
#include "AdTypes.h"

void print_scene(float speed_mps, uint32_t lane_idx);

LaneAssociationType_t handle_lateral_user_input(LaneAssociationType_t lane_idx,LateraAction_t lateral_action);

float handle_longitudinal_user_input(float speed_mps,LongitudinalAction_t de_increase_none);

void get_user_input(float * speed_mps, uint32_t *lane_idx);

#endif
