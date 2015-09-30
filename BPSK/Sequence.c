//
//  Sequence.c
//  BPSK
//
//  Created by huasheng gu on 15/9/30.
//  Copyright © 2015年 huasheng gu. All rights reserved.
//

#include "Sequence.h"

void EvenlyDis(double* evenseq , int L)
{
    int i;
    double u=0.0;
    static int x_seed = 22;
    static int y_seed = 25;
    static int z_seed = 8;
    //int x_seed,y_seed,z_seed;
    //srand((unsigned)time(NULL));
    //x_seed = rand()%30269;y_seed = rand()%30307;z_seed = rand()%30323;
    for(i=0;i<L;i++)
    {
        x_seed = 171*x_seed % 30269;
        y_seed = 170*y_seed % 30307;
        z_seed = 172*z_seed % 30323;
        u = x_seed/(double)30269+y_seed/(double)30307+z_seed/(double)30323;
        *evenseq = u - floor(u);
        evenseq++;
    }
}

void RayleighDis(double* evenseq , double* raylseq , int L)
{
    int i;
    for(i=0;i<L;i++)
    {
        *raylseq++ = sqrt(-2*log(*evenseq++));
    }
}

void GaussianNosieI(double* evenseq1 ,double* evenseq2, double* gaussianseq , int L)
{
    int i;
    for(i=0;i<L;i++)
    {
        *gaussianseq++ = sqrt(-2*log(*evenseq1))*cos(2*PI*(*evenseq2));
        evenseq1++;
        evenseq2++;
    }
}

void GaussianNoiseQ(double* evenseq1 ,double* evenseq2,double* gaussianseq , int L)
{
    int i;
    for(i=0;i<L;i++)
    {
        *gaussianseq++ = sqrt(-2*log(*evenseq2))*sin(2*PI*(*evenseq1));
        evenseq1++;
        evenseq2++;
    }
}
