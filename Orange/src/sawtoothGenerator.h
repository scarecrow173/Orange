#pragma once
#include "waveGenerator.h"
namespace Orange
{
	namespace Oscillator
	{
		class SawtoothGenerator : public WaveGenerator
		{
		public:
			SawtoothGenerator(double inSampleFrequency, double inFrequency, double inAmplitude);
			virtual void generate(int channels, int samples) override;
			virtual Common::AudioBuffer getBuffer() const override;
		private:
			Common::AudioBuffer Buffer;
            float time = 0;
		};
	}
}
