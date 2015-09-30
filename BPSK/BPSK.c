//
//  BPSK.c
//  BPSK
//
//  Created by huasheng gu on 15/9/30.
//  Copyright © 2015年 huasheng gu. All rights reserved.
//

#include "BPSK.h"


void BPSKmodeled(int* inputSeq, double* modeledSeq, int Lenth)
{
    int i;
    for(i = 1;i<Lenth;i++)
    {
        *modeledSeq = 1-2**inputSeq;
        modeledSeq++;
        inputSeq++;
    }
}

void BPSKdemodeled(double* modeledSeq, int* outputSeq, int Lenth)
{
    int i;
    for(i = 1;i<Lenth;i++)
    {
        if(*modeledSeq>0)
            *outputSeq = 0;
        else
            *outputSeq = 1;
        modeledSeq++;
        outputSeq++;
    }
}
