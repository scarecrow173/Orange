#pragma once
#include "waveGenerator.h"
namespace Orange
{
	namespace Oscillator
	{
		class SineGenerator : public WaveGenerator
		{
		public:
			SineGenerator(double inSampleFrequency, double inFrequency, double inAmplitude);
			virtual void generate(int channels, int samples) override;
			virtual Common::AudioBuffer getBuffer() const override;
		private:
			Common::AudioBuffer Buffer;
            float time = 0;
        };
	}
}
