#pragma once
#ifndef READWAV_H    
#define READWAV_H


int std_dev(float* data);
int dummy(float* data);
int fft(float* data);
int EEPD(float* data);
int PRE(float* data);
int RMSP(float* data);
int DF(float* data);
int spectral_features(float* data);
int SF_SSTD(float* data);
int SSL_SD(float* data);
int MFCC(float* data);
int CF(float* data);
int LGTH(float* data);
int PSD(float* data);

#endif
