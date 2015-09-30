//
//  BPSK.h
//  BPSK
//
//  Created by huasheng gu on 15/9/30.
//  Copyright © 2015年 huasheng gu. All rights reserved.
//

#ifndef BPSK_h
#define BPSK_h

#include <stdio.h>
#include "math.h"
#include <stdlib.h>
#include <time.h>
#define PI 3.1415926535898

extern void BPSKmodeled(int* inputSeq, double* modeledSeq, int Lenth);
extern void BPSKdemodeled(double* modeledSeq, int* outputSeq, int Lenth);


#endif /* BPSK_h */
