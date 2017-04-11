#include "commonalg.h"
#include "listalg.h"
#include "time_chrono.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
int PARENTS = 0;
int CHILDS  = 0;
int MUTANTS = 0;
// ------------ Test -----------------------
#define NUM_COMB 5
#define NUM_TEST 100                             //|
int test_parent[NUM_COMB] = {5,10,20,50,10};     //|
int test_child[NUM_COMB] = {5,10,20,50,10};      //|
int test_mutant[NUM_COMB] = {5,10,20,50,5};      //|
//-------------------------------------------
typedef struct
{
    sCoor coor;
    double fitnes;
}sChromosome;
typedef struct
{
    sChromosome chromosome;
    double time;
    double iter;
}sFeatChromosome;
typedef struct
{
    sChromosome   parent[50];
    sChromosome   child[50];
    sChromosome   mutant[50];
}sPopulation;
sPopulation gPopulation;
// -------------  function define ------------------------------------------------------
void  sort_chromosome(sChromosome* aChromosome,int kind);
void  reproduction();
void  mutation();
void  selection();
void  crossowing(int ch,  int a, int b);
void  inversion(int ch, int a, double eps);
void inversion_v2(int ch);
int convergenceTest(sChromosome* aData);
int convergenceTest_v2(sChromosome* aData);

sLine genetic_algorithm(unsigned int num_sys,unsigned int paren,unsigned int chil,unsigned int mut)
{
    PARENTS = paren;
    CHILDS  = chil;
    MUTANTS = mut;
    double elapsed_time = 0.0;
    sLine result;
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
    start_chrono();
    for(int i = 0; i < PARENTS; i++)
    {
        gPopulation.parent[i].coor.mX = getRandNum(MIN,MAX_X);
        gPopulation.parent[i].coor.mY = getRandNum(MIN,MAX_Y);
        gPopulation.parent[i].fitnes  = getValue(gPopulation.parent[i].coor);
     }
     sort_chromosome(gPopulation.parent,PARENTS);
     // find minimum value (during test)
     int iter = 0;
     int isFind = 0;
     // ---- Basic Loop --------------
      while(!isFind)
      {
           reproduction();
           mutation();
           selection();
           isFind = convergenceTest(gPopulation.parent);
           iter++;
           if(iter > MAX_LOOP)
               break;
      }
      // ------ END Basic Loop ----------
      elapsed_time = elapsed();
      result.coor.mX       = gPopulation.parent[0].coor.mX;
      result.coor.mY       = gPopulation.parent[0].coor.mY;
      result.value         = gPopulation.parent[0].fitnes;
      result.time          = elapsed_time;
      result.iter          = iter;
     /* printf("%g %g %g\n",result.coor.mX,result.coor.mY,result.value);
       system("pause");*/
      return result;
}
// -------------------- Sort Chromosome  --------------------------------------------------------------
void sort_chromosome(sChromosome* aChromosome,int kind)
{
    // bubble sort
    int i = 0;
    int j = 0;
    int flag = 0;
    sChromosome tmp;
    for(i = 0; i < kind; i++)
    {
        flag = 0;
        for(j = i+1; j < kind; j++)
        {
            if(aChromosome[j-1].fitnes > aChromosome[j].fitnes)
            {
                tmp = aChromosome[j-1];
                aChromosome[j-1] = aChromosome[j];
                aChromosome[j]   = tmp;
                flag = 1;
            }
        }
        if(!flag) return;
    }
}
// ------------------------- Reproduction -------------------------------------------------------------------------
void reproduction()
{
    int k = CHILDS - 1;
    //const double eps = 0.1; //version 2
    int i = 0;
    for(i = 0; i < (PARENTS/2); i++)
    {
        crossowing(k,i,PARENTS - 1 - i);
        k--;
        if(k < 0)
            return;
    }
    for(i = 0; i < (PARENTS/2); i++)
    {
        //inversion(k,i,eps); // version 2
        inversion_v2(k);
        k--;
        if(k < 0)
            return;
    }
    int random = 0;
    while(k >= 0)
    {
        random = rand()%PARENTS;
        gPopulation.child[k].coor.mX = gPopulation.parent[random].coor.mY;
        gPopulation.child[k].coor.mY = gPopulation.parent[random].coor.mX;
        gPopulation.child[k].fitnes  = getValue(gPopulation.child[k].coor);
        k--;
        if(k < 0)
            return;
    }
}
// ---------------------- Crossowing --------------------------------------------------------------
void crossowing(int ch, int a, int b)
{
    gPopulation.child[ch].coor.mX = (gPopulation.parent[a].coor.mX +
                                     gPopulation.parent[b].coor.mX)/2;
    gPopulation.child[ch].coor.mY = (gPopulation.parent[a].coor.mY +
                                     gPopulation.parent[b].coor.mY)/2;
    gPopulation.child[ch].fitnes  =  getValue(gPopulation.child[ch].coor);
}
// ---------------------------- Inversion -------------------------------------------------------------------------
void inversion(int ch, int a, double eps) //inversion: find by around point
{
  static int sign = 0;
  sign++;
  sign %= 2;
  if (sign == 0)
  {
      gPopulation.child[ch].coor.mX = gPopulation.parent[a].coor.mX - eps;
      gPopulation.child[ch].coor.mY = gPopulation.parent[a].coor.mY + eps;
      gPopulation.child[ch].fitnes  =  getValue(gPopulation.child[ch].coor);
  }
  else
  {
      gPopulation.child[ch].coor.mX =  gPopulation.parent[a].coor.mX + eps;
      gPopulation.child[ch].coor.mY =  gPopulation.parent[a].coor.mY - eps;
      gPopulation.child[ch].fitnes  =  getValue(gPopulation.child[ch].coor);
  }
}
// ------------------------ Inversion version 2 --------------------------------------------------------------------------
void inversion_v2(int ch) //inversion: find by around point
{
  // change bit L registr

    char* st_x = (char*)&(gPopulation.child[ch].coor.mX);
    char* st_y = (char*)&(gPopulation.child[ch].coor.mY);
    for(unsigned i = 2; i < (sizeof(double)); i++ )
    {
        *st_x = rand()%255;
        *st_y = rand()%255;
        st_x++;
        st_y++;
    }
    gPopulation.child[ch].fitnes  =  getValue(gPopulation.child[ch].coor);
}
// ------------------------- Mutation --------------------------------------------------------------------------
void mutation()
{
    double tmp = 0.0;
    for(int i = 0; i < MUTANTS; i++)
    {
        tmp = getRandNum(MIN,MAX_X);
        gPopulation.mutant[i].coor.mX = tmp;
        tmp = getRandNum(MIN,MAX_Y);
        gPopulation.mutant[i].coor.mY = tmp;
        gPopulation.mutant[i].fitnes = getValue(gPopulation.mutant[i].coor);
    }
}
// ---------------------- Selection --------------------------------------------------------------------------------
void selection()
{
    int i = 0;
    int j = 0;
    sChromosome tmp;
    while(j < PARENTS)
    {
        for(i = j; i < PARENTS; i++)
        {
           if(gPopulation.parent[j].fitnes > gPopulation.parent[i].fitnes)
           {
               tmp = gPopulation.parent[j];
               gPopulation.parent[j] = gPopulation.parent[i];
               gPopulation.parent[i] = tmp;
           }
        }
        for(i = 0; i < CHILDS; i++)
        {
            if(gPopulation.parent[j].fitnes > gPopulation.child[i].fitnes)
            {
                tmp = gPopulation.parent[j];
                gPopulation.parent[j] = gPopulation.child[i];
                gPopulation.child[i] = tmp;
            }
        }
        for(i = 0; i < MUTANTS; i++)
        {
            if(gPopulation.parent[j].fitnes > gPopulation.mutant[i].fitnes)
            {
                tmp = gPopulation.parent[j];
                gPopulation.parent[j] = gPopulation.mutant[i];
                gPopulation.mutant[i] = tmp;
            }
        }
        j++;
    }
}
// ---------------------- Convergence Test -----------------------------------------------------------------------------
int convergenceTest(sChromosome* aData)
{
    int i = 0;
    double dX = 0.0;
    double dY = 0.0;
    for(i = 1; i < PARENTS; i++)
    {
        dX = aData[i].coor.mX - aData[i-1].coor.mX;
        dY = aData[i].coor.mY - aData[i-1].coor.mY;
        if(dX < 0.0)
            dX = -dX;
        if(dY < 0.0)
            dY = -dY;
        if( (dX > 0.0001) || (dY > 0.0001) )
            return 0;
     }
    return 1;
}
// ---------------------- Convergence Test Version 2 --------------------------------------------------------
int convergenceTest_v2(sChromosome* aData)
{
    int i = 0;
    double dV = 0.0;
    for(i = 1; i < PARENTS; i++)
    {
        dV = aData[i].fitnes - aData[i-1].fitnes;
        if( dV < 0 )
            dV = -dV;
        if(dV > 0.001)
            return 0;
     }
    return 1;
}
