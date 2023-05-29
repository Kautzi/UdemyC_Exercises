#include <stdio.h>
#include <string.h>


#include "AdTypes.h"


static VehicleType  EGO_VEHICLE_DATA;
static VehicleType * VEHICLE_DATA[NUM_VEHICLES];

void preload_ego_vehicle_data(const char datapath[128])
{

char ego_datapath[128];
strncpy(ego_datapath,datapath,129);
strncat(ego_datapath,"/ego_data.txt",15);

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

void preload_vehicle_data(const char datapath[128])
{


}
