/* ----------------------------------------------------------------------
* Copyright (C) 2010-2012 ARM Limited. All rights reserved.
*
* $Date:         17. January 2013
* $Revision:     V1.4.0
*
* Project:       CMSIS DSP Library
* Title:             arm_fft_bin_example_f32.c
*
* Description:   Example code demonstrating calculation of Max energy bin of
*                frequency domain of input signal.
*
* Target Processor: Cortex-M4/Cortex-M3
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*   - Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   - Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in
*     the documentation and/or other materials provided with the
*     distribution.
*   - Neither the name of ARM LIMITED nor the names of its contributors
*     may be used to endorse or promote products derived from this
*     software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
 * -------------------------------------------------------------------- */
#include "arm_fft_bin_example_f32.h"
typedef float  float32_t;
typedef double float64_t;
/* ----------------------------------------------------------------------
* Max magnitude FFT Bin test
* ------------------------------------------------------------------- */
int32_t main(void)
{
	arm_status status;
	float32_t maxValue;
	status = ARM_MATH_SUCCESS;
	status = arm_cfft_init_f32(&varInstCfftF32, fftSize);
	/* Process the data through the CFFT/CIFFT module */
	arm_cfft_f32(&varInstCfftF32, testInput_f32_10khz, ifftFlag, doBitReverse);
	/* Process the data through the Complex Magnitude Module for
	calculating the magnitude at each bin */
	arm_cmplx_mag_f32(testInput_f32_10khz, testOutput, fftSize);
	/* Calculates maxValue and returns corresponding BIN value */
	arm_max_f32(testOutput, fftSize, &maxValue, &testIndex);
	status = (testIndex != refIndex) ? ARM_MATH_TEST_FAILURE : ARM_MATH_SUCCESS;

	if (status != ARM_MATH_SUCCESS)
	{
#if defined (SEMIHOSTING)
		printf("FAILURE\n");
#else
		while (1);                             /* main function does not return */
#endif
	}
	else
	{
#if defined (SEMIHOSTING)
		printf("SUCCESS\n");
#else
		while (1);                             /* main function does not return */
#endif
	}
}