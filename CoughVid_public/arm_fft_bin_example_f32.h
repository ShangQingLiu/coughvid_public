#pragma once
#ifndef ARM_FFT_H    
#define ARM_FFT_H 

#include "arm_math.h"
#include "arm_const_structs.h"

#if defined(SEMIHOSTING)
#include <stdio.h>
#endif
#define TEST_LENGTH_SAMPLES 2048
 /* -------------------------------------------------------------------
 * External Input and Output buffer Declarations for FFT Bin Example
 * ------------------------------------------------------------------- */
extern float32_t testInput_f32_10khz[TEST_LENGTH_SAMPLES];
static float32_t testOutput[TEST_LENGTH_SAMPLES / 2];
/* ------------------------------------------------------------------
* Global variables for FFT Bin Example
* ------------------------------------------------------------------- */
uint32_t fftSize = 1024;
uint32_t ifftFlag = 0;
uint32_t doBitReverse = 1;
arm_cfft_instance_f32 varInstCfftF32;
/* Reference index at which max energy of bin ocuurs */
uint32_t refIndex = 213, testIndex = 0;


int32_t test();

#endif