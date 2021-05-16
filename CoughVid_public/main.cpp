#include <iostream>
#include <readWav.h>
#include <string>
#include <arm_fft_bin_example_f32.h>

using namespace std;

int main() {
	
	// test fft
	test();

	//static const char waveFileName[] = "cough.wav";
	//readWavData(waveFileName);

	return 0;
}