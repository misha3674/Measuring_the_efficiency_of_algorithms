#include "commonalg.h"
#include "list2.h"
#include "time_chrono.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define NUM_TEST 100

typedef struct
{
    sCoor coor;
    sCoor velocity;
    sCoor best;
}sParticle;
sCoor gBestCoor;
int  num_pratticle = 10;
int convergenceTest_v3(sParticle* arr_particle)
{
    int i = 0;
    double dX = 0.0;
    double dY = 0.0;
    for(i = 1; i < num_pratticle; i++)
    {
        dX = arr_particle[i].best.mX - arr_particle[i-1].best.mX;
        dY = arr_particle[i].best.mY - arr_particle[i-1].best.mY;
        if(dX < 0.0)
            dX = -dX;
        if(dY < 0.0)
            dY = -dY;
        if( (dX > 0.01) || (dY > 0.01) )
            return 0;
    }
    return 1;
}
sLine particle_swarm_optimization(unsigned int num_sys, const unsigned num_prat, double kP,double kG,double parv)
{
    num_pratticle = num_prat;
    sParticle data_particle[num_prat];
    srand(time(0));

    float kofP = kP;
    float kofG = kG;

    switch(num_sys)
    {
        case 1:
            getRandNum = getRandNum_v1;
            getValue = getValue_v1;
        break;
        case 2:
            getRandNum = getRandNum_v2;
            getValue = getValue_v2;
        break;
        case 3:
            getRandNum = getRandNum_v3;
            getValue = getValue_v3;
        break;
        case 4:
            getRandNum = getRandNum_v3;
            getValue = getValue_v3;
        break;
        default: num_sys = 1; break;
    }
    int r_p = 0;
    int r_g = 0;
    int isFind = 0;
    int iter = 0;
    double elapsed_time = 0.0;
    sLine result;
        isFind = 0;
        iter   = 0;
        start_chrono();
        for(int i = 0; i < num_pratticle; i++)
        {
            data_particle[i].coor.mX = getRandNum(MIN,MAX_X);
            data_particle[i].best.mX =  data_particle[i].coor.mX;
            data_particle[i].velocity.mX = 0.001;
            data_particle[i].coor.mY = getRandNum(MIN,MAX_Y);
            data_particle[i].best.mY =  data_particle[i].coor.mY;
            data_particle[i].velocity.mY = 0.001;
        }
        // find best particle
        gBestCoor = data_particle[0].best;
        for(int i = 0; i < num_pratticle; i++)
        {
            if( getValue( data_particle[i].best ) < getValue( gBestCoor ) )
                gBestCoor = data_particle[i].best;
        }
        while( !isFind ) // ? < 10 000
        {
             for(int i = 0; i < num_pratticle; i++)
             {
                 r_p = (rand()%100)%2; // 0 - 1
                 r_g = (rand()%100)%2;
                 // calculate
                 data_particle[i].velocity.mX = parv*data_particle[i].velocity.mX + kofP*r_p*(data_particle[i].best.mX - data_particle[i].coor.mX)+
                                                           kofG*r_g*(gBestCoor.mX - data_particle[i].coor.mX);
                 data_particle[i].coor.mX += data_particle[i].velocity.mX;
                 if( (data_particle[i].coor.mX < MIN) || (data_particle[i].coor.mX > MAX_X))
                 {
                     data_particle[i].coor.mX = getRandNum(MIN,MAX_X);
                     data_particle[i].velocity.mX = 0.0;
                 }
                 data_particle[i].velocity.mY = parv*data_particle[i].velocity.mY + kofP*r_p*(data_particle[i].best.mY - data_particle[i].coor.mY)+
                                                           kofG*r_g*(gBestCoor.mY - data_particle[i].coor.mY);
                 data_particle[i].coor.mY += data_particle[i].velocity.mY;
                 if( (data_particle[i].coor.mY < MIN) || (data_particle[i].coor.mY > MAX_Y))
                 {
                     data_particle[i].coor.mY = getRandNum(MIN,MAX_Y);
                     data_particle[i].velocity.mY = 0.0;
                 }
                 if( getValue(data_particle[i].coor) < getValue( data_particle[i].best ) )
                     data_particle[i].best = data_particle[i].coor;
                 if( getValue( data_particle[i].best ) < getValue( gBestCoor ) )
                     gBestCoor = data_particle[i].best;
             }
             isFind = convergenceTest_v3(data_particle);
             iter++;
        }
       elapsed_time = elapsed();
       result.coor.mX = gBestCoor.mX;
       result.coor.mY = gBestCoor.mY;
       result.value = getValue(gBestCoor);
       result.time = elapsed_time;
       result.iter = iter;
       return result;
       /*printf("%g %g %g\n",result.coor.mX,result.coor.mY,result.value);
       system("pause");*/
}

