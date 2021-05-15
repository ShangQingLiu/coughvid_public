#include <iostream>
#include <readWav.h>
#include <string>

using namespace std;

int main() {
	
	static const char waveFileName[] = "cough.wav";
	readWav(waveFileName);

	return 0;
}