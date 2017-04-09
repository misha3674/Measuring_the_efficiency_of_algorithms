#include "commonalg.h"
#include <math.h>
#include <stdlib.h>
#define PRECISION 0.0005
//---------------------------------------------------------------------------------------------------
double calculateDelatFunction_v1(double x1, double x2)
{
    double f1 = (double)( 4*x1*x1 + 4*x2*x2);
    double f2 = (double)( (x1-5)*(x1-5) + (x2-5)*(x2-5) );
    return (f1 - f2);
}
double value_v1(double x1, double x2)
{
   return (double)((x1-5)*(x1-5) + (x2-5)*(x2-5) );
}
double getRandNum_v1(float min, float max)
{
    double tmp = 0.0;
    const int NUM = 100000000;
    tmp = (double)(fabs((double)((rand() * NUM) % (int)((max - min)*NUM) + 1) / NUM) + min);
    return tmp;
}
double getValue_v1(sCoor aCoor)
{
       double calc = 0.0f;
       double dF = calculateDelatFunction_v1(aCoor.mX,aCoor.mY);
       calc = value_v1(aCoor.mX,aCoor.mY);
       if( (dF*dF) > PRECISION)
           return 70*pow(2,calc);
       return calc;
}
//---------------------------------------------------------------------------------------------------
double calculateDelatFunction_v2(double x1, double x2)
{
    double f1 = (double)( 2 + (x1-2)*(x1-2) + (x2-1)*(x2-1));
    double f2 = (double)( 9*x1 - (x2-1)*(x2-1) );
    return (f1 - f2);
}
double value_v2(double x1, double x2)
{
   return (double)( 9*x1 - (x2-1)*(x2-1) );
}
double getValue_v2(sCoor aCoor)
{
       double calc = 0.0f;
       double dF = calculateDelatFunction_v2(aCoor.mX,aCoor.mY);
       calc = value_v2(aCoor.mX,aCoor.mY);
       if( (dF*dF) > PRECISION)
           return 769+calc*calc;
       return calc;
}
double getRandNum_v2(float min, float max)
{
    double tmp = 0.0;
    const int NUM = 100000000;
    tmp = (double)(fabs((double)((rand() * NUM) % (int)((max - min)*NUM) + 1) / NUM) + min);
    return tmp;
}
//---------------------------------------------------------------------------------------------------
double calculateDelatFunction_v3(double x1, double x2)
{
    double f1 = (double)( x1 );
    double f2 = (double)( (1+x2)*exp(-x1/(1+x2)) );
    return (f1 - f2);
}
double value_v3(double x1, double x2)
{
    x2 = 0;
    return (double)(x1 + x2 );
}
double getValue_v3(sCoor aCoor)
{
       double calc = 0.0f;
       double dF = calculateDelatFunction_v3(aCoor.mX,aCoor.mY);
       calc = value_v3(aCoor.mX,aCoor.mY);
       if( (dF*dF) > PRECISION)
           return 70*pow(2,calc);
       return calc;
}
double getRandNum_v3(float min, float max)
{
    double tmp = 0.0;
    const int NUM = 100000000;
    tmp = (double)(fabs((double)((rand() * NUM) % (int)((max - min)*NUM) + 1) / NUM) + min);
    return tmp;
}
//---------------------------------------------------------------------------------------------------
double calculateDelatFunction_v4(double x1, double x2)
{
    double f1 = (double)( x1 );
    double f2 = (double)( (1+x2)/x1 );
    return (f1 - f2);
}
double value_v4(double x1, double x2)
{
    x2 = 0;
    return (double)(x1 + x2 );
}
double getValue_v4(sCoor aCoor)
{
       double calc = 0.0f;
       double dF = calculateDelatFunction_v4(aCoor.mX,aCoor.mY);
       calc = value_v4(aCoor.mX,aCoor.mY);
       if( (dF*dF) > PRECISION)
           return 70*pow(2,calc);
       return calc;
}
double getRandNum_v4(float min, float max)
{
    double tmp = 0.0;
    const int NUM = 100000000;
    tmp = (double)(fabs((double)((rand() * NUM) % (int)((max - min)*NUM) + 1) / NUM) + min);
    return tmp;
}

