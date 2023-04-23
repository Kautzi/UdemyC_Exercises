#include <stdint.h>
#include <stdio.h>

//### Types ###
typedef enum LaneAssociatedType
{

    RIGHT=1,
    CENTER,
    LEFT,
    Unknown,
}LaneAssociatedType_t;

//### END Types ###

//### Function Declaration ###
void print_lane(LaneAssociatedType_t lane);
//### END Declaration ###


//### MAIN ###
int main()
{
    //### Variables ###
    uint32_t current_speed = 0;
    uint32_t current_lane = 0;
    //### END Variables ###

    //### Insert speed and lane
    printf("Insert current speed:\n");
    scanf("%u",&current_speed);
    printf("Insert current Lane (1=Right, 2=Center, 3=Left):\n");
    scanf("%u",&current_lane);


    printf("Create the properties of a vehicle.\n");
    printf("Speed in m/s: %u\n",current_speed);
    printf("Lane(1=Right, 2=Center, 3=Left): %u\n",current_lane);

    print_lane(current_lane);





    return 0;
}
//### END MAIN ###

//### Function Definition ###

void print_lane(LaneAssociatedType_t lane)
{
    printf("      L   C   R     \n");
    switch(lane)
    {
        case LEFT:
        {
        printf("    | V |   |   |   \n");
        break;
        }

        case CENTER:
        {
        printf("    |   | V |   |   \n");
        break;
        }

        case RIGHT:
        {
        printf("    |   |   | V |   \n");
        break;
        }
        default:
        printf("Unknowen Lane\n");
    }
}
