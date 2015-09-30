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

extern void EvenlyDis(double* enevseq , int L);
extern void RayleighDis(double* evenseq , double* raylseq ,  int L);
extern void GaussianNosieI(double* enevseq1 , double* enevseq2 , double* gaussianseq , int L);
extern void GaussianNoiseQ(double* enevseq1 , double* enevseq2 , double* gaussianseq , int L);


#endif /* Sequence_h */
