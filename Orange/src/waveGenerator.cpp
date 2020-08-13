#include "waveGenerator.h"

using namespace Orange::Oscillator;

WaveGenerator::WaveGenerator(double inSampleRate, double inFrequency, double inAmplitude)
	: sampleRate(inSampleRate), frequency(inFrequency), amplitude(inAmplitude), phase(1.0)
{

}
WaveGenerator::~WaveGenerator()
{

}