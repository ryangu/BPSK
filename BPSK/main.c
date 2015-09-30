//
//  main.c
//  BPSK
//
//  Created by huasheng gu on 15/9/30.
//  Copyright © 2015年 huasheng gu. All rights reserved.
//

#include"BPSK.c"
#include"Sequence.c"
#define N 10000

extern void AWGN(double* modedP,double* receivedP,double SNR,int L);


int main()
{
    int infoBit[N],demodedBit[N];
    double modedSeq[N],receivedSeq[N];
    int count,SNRnum=11;
    double SNR[11] = {0,1,2,3,4,5,6,7,8,9,10};
    double ber[11];
    double totalbit,errorbit,errorlimit=50;
    int i;
    FILE *fp;
    
    for(count=0;count<SNRnum;count++)
    {
        errorbit=0;totalbit=0;
        while(errorbit<errorlimit)
        {
            srand((unsigned)time(NULL));
            for(i=0;i<N;i++)
            {
                infoBit[i] = rand()%2;
                //printf("%2d",infoSequ[i]);
            }
            //printf("\n");
            totalbit += N;
            
            BPSKmodeled(infoBit,modedSeq,N);
            AWGN(modedSeq,receivedSeq,SNR[count],N);
            //awgn(SNR[count],modedSeq,receivedSeq);
            BPSKdemodeled(receivedSeq,demodedBit,N);
            
            for(i=0;i<N;i++)
            {
                if(infoBit[i]!=demodedBit[i])
                    errorbit++;
            }
        }
        ber[count] = errorbit/totalbit;
    }
    
    if((fp=fopen("BERresult.txt","w"))==NULL)
        printf("can't open the file!\n");
    else
        for(i=0;i<SNRnum;i++)
        {
            fprintf(fp,"%f ",ber[i]);
            printf("%f",ber[i]);
            printf("\n");
        }
    fclose(fp);
    system("pause");
    return 0;
}


void AWGN(double* modedP,double* receivedP,double SNR,int L)
{
    int i;
    double EvenSeq1[N],EvenSeq2[N],GaussianSeqI[N],sigma2,energy=0,mean=0;
    EvenlyDis(EvenSeq1 , N);
    EvenlyDis(EvenSeq2 , N);
    GaussianNosieI(EvenSeq1 , EvenSeq2 ,GaussianSeqI , N);
    sigma2 = 1/(2*pow(10,(SNR/10)));
    for(i=0;i<L;i++)
    {
        *receivedP = *modedP + sqrtl(sigma2) * GaussianSeqI[i];
        modedP++;
        receivedP++;
        energy +=  GaussianSeqI[i]*GaussianSeqI[i];
        mean += GaussianSeqI[i];
    }
    energy = energy/L;
}