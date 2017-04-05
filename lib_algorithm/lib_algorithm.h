#ifndef LIB_ALGORITHM_H
#define LIB_ALGORITHM_H

typedef struct
{
   int mX;
   int mY;
}sCoor1;
typedef struct
{
    double min_value;
    double max_time;
    int    test_num;
}sHeaderFile;
typedef struct
{
    sCoor1  coor;
    double value;
    double time;
    int    iter;
}sLine;
sHeaderFile genetic_algorithm(int,sLine*);
sHeaderFile simulated_annealing_algorithm(int,sLine*);
sHeaderFile particle_swarm_algorithm(int,sLine*);
#endif // LIB_ALGORITHM_H
