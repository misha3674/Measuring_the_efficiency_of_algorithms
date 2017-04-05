#include "innit.h"
#include "common.h"
#include "lib_algorithm/lib_algorithm.h"

sHeaderFile headGA;
sHeaderFile headSA;
sHeaderFile headPA;
sLine lineGA[NUM_OF_TEST];
sLine linePA[NUM_OF_TEST];
sLine lineSA[NUM_OF_TEST];

sScaleInform scaleInfoGA;
sScaleInform scaleInfoPA;
sScaleInform scaleInfoSA;
sBar  grafGA[NUM_OF_TEST];
sBar  grafSA[NUM_OF_TEST];
sBar  grafPA[NUM_OF_TEST];

int chosed_func = 1;
void init_results()
{
    double delta_scale_value = 1; // 111111
    double delta_scale_time = 0.1; // 0.1
    // read data of algorithm's work
    headGA = genetic_algorithm(chosed_func,&lineGA[0]);
    headSA = simulated_annealing_algorithm(chosed_func,&lineSA[0]);
    headPA = particle_swarm_algorithm(chosed_func,&linePA[0]);
    // calculate low/high scale
    scaleInfoGA.valueL = headGA.min_value;
    scaleInfoGA.valueH = scaleInfoGA.timeL + delta_scale_value;
    scaleInfoGA.timeH  = headGA.max_time;
    scaleInfoGA.timeL  = scaleInfoGA.timeH - delta_scale_time;

    scaleInfoPA.valueL = headPA.min_value;
    scaleInfoPA.valueH = scaleInfoPA.timeL + delta_scale_value;
    scaleInfoPA.timeH  = headPA.max_time;
    scaleInfoPA.timeL  = scaleInfoPA.timeH - delta_scale_time;

    scaleInfoSA.valueL = headSA.min_value;
    scaleInfoSA.valueH = scaleInfoSA.timeL + delta_scale_value;
    scaleInfoSA.timeH  = headSA.max_time;
    scaleInfoSA.timeL  = scaleInfoSA.timeH - delta_scale_time;
    // conver line into sBar (for drawing)
    for(int i = 0; i < NUM_OF_TEST; i++)
    {
        double time_work = 0.;
        double find_value = 0.;
        // bringing value to scale size
        // percent % all height scale
            // GA
        time_work  = lineGA[i].time;
        find_value = lineGA[i].value;
        grafGA[i].pos = i;
        if(find_value > scaleInfoGA.valueH)
            grafGA[i].value = -1; // value out of range
        else
            grafGA[i].value = (find_value - scaleInfoGA.valueL)/delta_scale_value;
        if(time_work < scaleInfoPA.timeL)
            grafGA[i].time = -1; // value out of range
        else
            grafGA[i].time = (find_value - scaleInfoGA.valueL)/delta_scale_time;
            //PA
        time_work  = linePA[i].time;
        find_value = linePA[i].value;
        grafPA[i].pos = i;
        if(find_value > scaleInfoPA.valueH)
            grafPA[i].value = -1; // value out of range
        else
            grafPA[i].value = (find_value - scaleInfoPA.valueL)/delta_scale_value;
        if(time_work < scaleInfoPA.timeL)
            grafPA[i].time = -1; // value out of range
        else
            grafPA[i].time = (find_value - scaleInfoPA.valueL)/delta_scale_time;
            //SA
        time_work  = lineSA[i].time;
        find_value = lineSA[i].value;
        grafSA[i].pos = i;
        if(find_value > scaleInfoSA.valueH)
            grafSA[i].value = -1; // value out of range
        else
            grafSA[i].value = (find_value - scaleInfoSA.valueL)/delta_scale_value;
        if(time_work < scaleInfoSA.timeL)
            grafSA[i].time = -1; // value out of range
        else
            grafSA[i].time = (find_value - scaleInfoSA.valueL)/delta_scale_time;
    }
    for(int i = 0; i < NUM_OF_TEST; i++)
    {
        if(grafGA[i].value != (-1))
            scaleGA.height_barV[i] = (int)((height_scale - 5)*(grafGA[i].value)) + 5;
        else
            scaleGA.height_barV[i] = 4;
        if(grafGA[i].time != (-1))
            scaleGA.height_barT[i] = (int)((height_scale - 5)*(grafGA[i].time))  + 5;
        else
            scaleGA.height_barT[i] = 4;

        if(grafPA[i].value != (-1))
            scalePA.height_barV[i] = (height_scale - 5)*(grafPA[i].value) + 5;
        else
            scalePA.height_barV[i] = 4;

        if(grafPA[i].time != (-1))
            scalePA.height_barT[i] = (height_scale - 5)*(grafPA[i].time)  + 5;
        else
            scalePA.height_barT[i] = 4;

        if(grafSA[i].value != (-1))
            scaleSA.height_barV[i] = (height_scale - 5)*(grafSA[i].value) + 5;
        else
            scaleSA.height_barV[i] = 4;

        if(grafSA[i].time != (-1))
            scaleSA.height_barT[i] = (height_scale - 5)*(grafSA[i].time)  + 5;
        else
            scaleSA.height_barT[i] = 4;
    }
    scaleGA.mX = 1;
    scaleGA.mY = 5; //5
    scalePA.mX = 1;
    scalePA.mY = 5+20+5; // 30
    scaleSA.mX = 1;
    scaleSA.mY = 55;
}
void innit_settings()
{

}
