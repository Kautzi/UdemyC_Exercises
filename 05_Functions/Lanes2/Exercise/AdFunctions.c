#include "AdTypes.h" // for ENUM Lane
#include "AdFunctions.h" //for lane_scene print
#include <stdio.h> //for printf ...
#include <stdint.h> //for uint32_t...

//### FUNCTION DEFINITION ###

void print_scene(float speed_mps, uint32_t lane_idx)
{
switch(lane_idx)
{
    case RIGHT:
    {
        printf("\t  L   C   R  \n");
        printf("\t|   |   | V |\n");
        printf("Speed: %f\n",speed_mps);
        break;
    }
    case CENTER:
    {
        printf("\t  L   C   R  \n");
        printf("\t|   | V |   |\n");
        printf("Speed: %f\n",speed_mps);
        break;
    }
    case LEFT:
    {
        printf("\t  L   C   R  \n");
        printf("\t| V |   |   |\n");
        printf("Speed: %f\n",speed_mps);
        break;
    }
    case UNKNOWEN:
    default:
        printf("UNKNOWN LANE");
        break;
}
}

//### END FUNCTION DEFINITION ###
