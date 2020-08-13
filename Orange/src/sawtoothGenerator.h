#pragma once
#include "waveGenerator.h"
namespace Orange
{
	namespace Oscillator
	{
		class SawtoothGenerator : public WaveGenerator
		{
		public:
			SawtoothGenerator(double inSampleRate, double inFrequency, double inAmplitude);
			virtual void generate(int channels, int samples) override;
			virtual Common::AudioBuffer<float> getBuffer() const override;

		private:
			Common::AudioBuffer<float> Buffer;
            float time = 0;
		};
	}
}
