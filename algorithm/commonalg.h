#ifndef COMMONALG_H
#define COMMONALG_H

#define MAX_X  5
#define MAX_Y  5
#define MIN    0
typedef struct
{
   double mX;
   double mY;
}sCoor;
typedef struct
{
    sCoor coor;
    double value;
    double time;
    int iter;
}sLine;

double (*getRandNum)(float min, float max);
double (*getValue)(sCoor aCoor);

double getRandNum_v1(float min, float max);
double getValue_v1(sCoor aCoor);

double getRandNum_v2(float min, float max);
double getValue_v2(sCoor aCoor);

double getRandNum_v3(float min, float max);
double getValue_v3(sCoor aCoor);

double getRandNum_v4(float min, float max);
double getValue_v4(sCoor aCoor);

#endif // COMMON_H
