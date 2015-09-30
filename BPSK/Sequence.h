//
//  Sequence.h
//  BPSK
//
//  Created by huasheng gu on 15/9/30.
//  Copyright © 2015年 huasheng gu. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h


#include"BPSK.h"

void EvenlyDis(double* enevseq , int L);
void RayleighDis(double* evenseq , double* raylseq ,  int L);
void GaussianNosieI(double* enevseq1 , double* enevseq2 , double* gaussianseq , int L);
void GaussianNoiseQ(double* enevseq1 , double* enevseq2 , double* gaussianseq , int L);


#endif /* Sequence_h */
