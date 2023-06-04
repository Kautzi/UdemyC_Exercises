#include <stdio.h>
#include <string.h>
#include <stdint.h>


#include "AdTypes.h"


static VehicleType  EGO_VEHICLE_DATA;
static VehicleType VEHICLE_DATA[NUM_VEHICLES][NUM_CYCLES];

void preload_ego_vehicle_data(const char datapath[128], int use_case_idx)
{

char ego_file[17];
char ego_datapath[128];
strncpy(ego_datapath,datapath,129);

sprintf(ego_file,"%d/ego_data.txt",use_case_idx);

/*alt
switch(use_case_idx)
{
    case 0:
    {
        strncpy(ego_file,"0/ego_data.txt",strlen("0/ego_data.txt"));
        break;
    }

    case 1:
    {
        strncpy(ego_file,"1/ego_data.txt",strlen("1/ego_data.txt"));
        break;
    }

    case 2:
    {
        strncpy(ego_file,"2/ego_data.txt",strlen("2/ego_data.txt"));
        break;
    }

    default:
    {

        break;
    }

}
*/

strncat(ego_datapath,ego_file,18);

FILE *fp = fopen(ego_datapath,"r");

if(fp == NULL)
{
    printf("File: %s can't be opened!\n",datapath);
    fclose(fp);
    return;
}

fscanf(fp,"%*s %u",&EGO_VEHICLE_DATA.lane);

fscanf(fp,"%*s %f",&EGO_VEHICLE_DATA.speed);

EGO_VEHICLE_DATA.Vehicle_ID=EGO_ID;

EGO_VEHICLE_DATA.distance_to_ego_ID=0;

fclose(fp);
}

void preload_vehicle_data(const char datapath[128], int use_case_idx)
{
char neighbore_file[23];//19 chars and 0 is at pos 9

sprintf(neighbore_file,"%d/vehicle_0_data.txt",use_case_idx);


char neighbore_datapath[128]={'\0'};
char num = '0';
//START for loop #1
for(int i= 0; i < NUM_VEHICLES; i++)
{
    neighbore_file[10]=(i == 0) ? num : ++num;

    strncpy(neighbore_datapath,datapath,80);

    strncat(neighbore_datapath, neighbore_file, 24);

    FILE *fp = fopen(neighbore_datapath,"r");

    if(fp == NULL)
    {
        printf("File: %s can't be opened!\n",datapath);
        fclose(fp);
        return;
    }
    int j = 0;
    //scan Lane and Distance only once for every vehicle
        fscanf(fp,"%*s %u",&VEHICLE_DATA[i][j].lane);

        fscanf(fp,"%*s %f",&VEHICLE_DATA[i][j].distance_to_ego_ID);

        VEHICLE_DATA[i][j].Vehicle_ID=i;

    for(; j < NUM_CYCLES;j++)
    {
        VEHICLE_DATA[i][j]=VEHICLE_DATA[i][0];
        fscanf(fp,"%*s %*s %f",&VEHICLE_DATA[i][j].speed);

    }

    fclose(fp);
}//END for loop #1

}

void init_ego_vehicle(VehicleType *ego_vehicle)
{

*ego_vehicle = EGO_VEHICLE_DATA;

}

void init_vehicle(VehicleType *vehicle, const int32_t id, const uint32_t cycle)
{

        vehicle[id]=VEHICLE_DATA[id][cycle];

}
void init_vehicles(NeighborVehiclesType *vehicles)
{
    //#1 START FOR()
    for(uint32_t i = 0; i < NUM_VEHICLES;i++)
    {
        //#1 START SWITCH()
        switch(VEHICLE_DATA[i][0].lane)
        {
            case LANE_ASSOCIATION_TYPE_LEFT:
            {
                if(VEHICLE_DATA[i][0].distance_to_ego_ID >= 0)
                {
                    vehicles->vehicles_left_lane[0]=VEHICLE_DATA[i][0];
                }
                else
                {
                    vehicles->vehicles_left_lane[1]=VEHICLE_DATA[i][0];
                }

            break;
            }

            case LANE_ASSOCIATION_TYPE_CENTER:
            {
                if(VEHICLE_DATA[i][0].distance_to_ego_ID >= 0)
                {
                    vehicles->vehicles_center_lane[0]=VEHICLE_DATA[i][0];
                }
                else
                {
                    vehicles->vehicles_center_lane[1]=VEHICLE_DATA[i][0];
                }
            break;
            }

            case LANE_ASSOCIATION_TYPE_RIGHT:
            {
                if(VEHICLE_DATA[i][0].distance_to_ego_ID >= 0)
                {
                    vehicles->vehicles_right_lane[0]=VEHICLE_DATA[i][0];
                }
                else
                {
                    vehicles->vehicles_right_lane[1]=VEHICLE_DATA[i][0];
                }
            break;
            }

            case LANE_ASSOCIATION_TYPE_NONE:
            default:
            {
                break;
            }
        }//#1 END SWITCH

    }//#1 END FOR()
}


void load_cycle(NeighborVehiclesType *vehicles, const uint32_t cycle)
{
    vehicles->vehicles_left_lane[0].speed= VEHICLE_DATA[0][cycle].speed;
    vehicles->vehicles_left_lane[1].speed= VEHICLE_DATA[1][cycle].speed;
    vehicles->vehicles_center_lane[0].speed= VEHICLE_DATA[2][cycle].speed;
    vehicles->vehicles_center_lane[1].speed= VEHICLE_DATA[3][cycle].speed;
    vehicles->vehicles_right_lane[0].speed= VEHICLE_DATA[4][cycle].speed;
    vehicles->vehicles_right_lane[1].speed= VEHICLE_DATA[5][cycle].speed;
}
