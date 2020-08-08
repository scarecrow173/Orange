#pragma once
#include "waveGenerator.h"
namespace Orange
{
	namespace Oscillator
	{
		class PinkNoiseGenerator : public WaveGenerator
		{
		public:
			PinkNoiseGenerator(double inSampleFrequency, double inFrequency, double inAmplitude);
			virtual void generate(int channels, int samples) override;
			virtual Common::AudioBuffer getBuffer() const override;
		private:
			Common::AudioBuffer Buffer;
		};
	}
}