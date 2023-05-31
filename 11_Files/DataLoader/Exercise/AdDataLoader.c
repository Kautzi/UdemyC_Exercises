#include <stdio.h>
#include <string.h>


#include "AdTypes.h"


static VehicleType  EGO_VEHICLE_DATA;
static VehicleType VEHICLE_DATA[NUM_VEHICLES][NUM_CYCLES];

void preload_ego_vehicle_data(const char datapath[128])
{

char ego_datapath[128];
strncpy(ego_datapath,datapath,129);
strncat(ego_datapath,"ego_data.txt",15);

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
char neighbore_file[20]={"vehicle_0_data.txt"};//19 chars and 0 is at pos 9

char neighbore_datapath[128]={'\0'};
char num = '0';
//START for loop #1
for(int i= 0; i <= NUM_VEHICLES; i++)
{
    neighbore_file[8]=(i == 0) ? num : ++num;

    strncpy(neighbore_datapath,datapath,80);

    strncat(neighbore_datapath, neighbore_file, 25);

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

    for(; j <= NUM_CYCLES;j++)
    {
        VEHICLE_DATA[i][j]=VEHICLE_DATA[i][0];
        fscanf(fp,"%*s %*s %f",&VEHICLE_DATA[i][j].speed);

    }

    fclose(fp);
}//END for loop #1

}
