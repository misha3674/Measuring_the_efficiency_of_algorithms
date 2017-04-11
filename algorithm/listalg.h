#ifndef LIST2_H
#define LIST2_H


sLine simulatedAnnealing(unsigned int sys, double init,  double end, double a,  double b);
sLine genetic_algorithm(unsigned int num_sys,unsigned int paren,unsigned int chil,unsigned int mut);
sLine particle_swarm_optimization(unsigned int sys,const unsigned num_prat, double kP,double kG,double parv);

#endif // LIST2_H
