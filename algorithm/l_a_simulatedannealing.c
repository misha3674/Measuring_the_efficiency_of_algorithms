#include "commonalg.h"
#include "list2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "time_chrono.h"
#define NUM_TEST 100
typedef sCoor sState;
typedef enum
{
   MINUS = 0,
   PLUS,
   NONE,
   END_SIGN
}eSign;

double lA = 0.;
double lB = 0.;
// ------------------------------------------------------------------------------
double decreaseTemperatute(double initialTemperature, int i);
int getTaransitionProbability(double t);
bool isTransition(int probability);
sState generateStateCandidate(sState previousState, int iter);
sLine simulatedAnnealing_r(sState* primaryState, double initialTemperature, double endTemperature);
// ------------------------------------------------------------------------------
sLine simulatedAnnealing(unsigned int num_sys,
                         double inniTempr,
                         double endTempr,
                         double a,
                         double b)
{
    sState optimState;
    sLine result;
    lA = a;
    lB = b;
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
    optimState.mX = 0;
    optimState.mY = 0;
    result = simulatedAnnealing_r(&optimState,inniTempr, endTempr);
    return result;
}
// ------------------------------------------------------------------------------
double decreaseTemperatute(double currentTemperature, int i)
{
       double temperature = 0.0f;
       temperature = (double)(lA*currentTemperature/pow(i,lB));
       return temperature;
}
// ------------------------------------------------------------------------------
int getTaransitionProbability(double t)
{
    int p = 0;
    p = (int) ( (1 - exp(-t*10.0))*100.0 );
    // speed dercease  Taransition Probability
    return p;
}
// ------------------------------------------------------------------------------
bool isTransition(int probability)
{
     int value = 0;
         value = rand()%100+1;
     bool is = 0;
     if(value <= probability)
          is = 1;
     else
         is = 0;
     return is;
}
// ------------------------------------------------------------------------------
sState generateStateCandidate(sState previousState, int iter)
{
       eSign sign = MINUS;
       sState newState;
       double kof = 0.3;
       int n = 0;
       sign = (int)(rand()%(END_SIGN*1000))/1000;

       for(n = 0; n < iter; n+=100);//70 // 100
           n /=20;  //5 // 20
       double add = 0.0;
       switch(sign)
       {
           case MINUS:
           {
              add = -kof/n;
              break;
           }
           case PLUS:
           {
              add = kof/n;
              break;
           }
           case NONE:
           case END_SIGN: break;
       }
       newState.mX = previousState.mX + add;
       if( (newState.mX >= MAX_X) || (newState.mX < MIN))
           newState.mX = previousState.mX - 1.5*add;

       sign = (int)(rand()%(END_SIGN*1000))/1000;
       switch(sign)
       {
           case MINUS:
           {
              add = -kof/n;
              break;
           }
           case PLUS:
           {
              add = kof/n;
              break;
           }
           case NONE:
           case END_SIGN: break;
       }
       newState.mY = previousState.mY + add;
       if((newState.mY >= MAX_Y) || (newState.mY < MIN))
           newState.mY = previousState.mY - 1.5*add;

       return newState;
}
// ------------------------------------------------------------------------------
sLine simulatedAnnealing_r(sState* primaryState, double initialTemperature, double endTemperature)
{
     double currentTemp = 0.0f;
     double currentEnergy   = 0.0f;
     double candidateEnergy = 0.0f;
     sState sCandidat;
            sCandidat.mX = 0.0f;
            sCandidat.mY = 0.0f;
     double elapsed_time = 0.0;
     sLine result;
     int iter = 0;
         start_chrono();
         currentTemp = initialTemperature;
         int p = 0;
         primaryState->mX = getRandNum(MIN,MAX_X);
         primaryState->mY = getRandNum(MIN,MAX_Y);
         iter = 1;
         while(iter < MAX_LOOP)
         {
             currentEnergy = getValue(*primaryState); // ?????
             sCandidat = generateStateCandidate(*primaryState, iter);
             candidateEnergy = getValue(sCandidat);
             if(candidateEnergy < currentEnergy) // dE < 0
                    *primaryState = sCandidat;
             else
             {
                 p = getTaransitionProbability(currentTemp); // dE > 0
                 if(isTransition(p))
                 {
                     primaryState->mX = getRandNum(MIN,MAX_X);
                     primaryState->mY = getRandNum(MIN,MAX_Y);
                 }
             }
             currentTemp = decreaseTemperatute(initialTemperature, iter);
             if(endTemperature > currentTemp)
                 break;
             iter++;
         }
        elapsed_time = elapsed();
        result.coor.mX = primaryState->mX;
        result.coor.mY = primaryState->mY;
        result.value = getValue(*primaryState);
        result.time = elapsed_time;
        result.iter = iter;
        return result;
        /*printf("%g %g %g\n",lineFile.coor.mX,lineFile.coor.mY,lineFile.value);
        system("pause");*/
}
