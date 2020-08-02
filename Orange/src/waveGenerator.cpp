#include "waveGenerator.h"

using namespace Orange::Oscillator;

WaveGenerator::WaveGenerator(double inSampleFrequency, double inFrequency, double inAmplitude)
	: sampleFrequency(inSampleFrequency), frequency(inFrequency), amplitude(inAmplitude), phase(1.0)
{

}
WaveGenerator::~WaveGenerator()
{

}