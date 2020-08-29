#pragma once
#include "waveGenerator.h"
#include "audioTime.h"
namespace Orange
{
	namespace Oscillator
	{
		class SineGenerator : public WaveGenerator
		{
		public:
			SineGenerator(double inSampleRate, double inFrequency, double inAmplitude);
			virtual void generate(int channels, int samples) override;
			virtual Common::AudioBuffer<float> getBuffer() const override;
		private:
			Common::AudioBuffer<float> Buffer;
            Common::AudioTime time;
        };
	}
}
