#pragma once
#include "waveGenerator.h"
namespace Orange
{
	namespace Oscillator
	{
		class WhiteNoiseGenerator : public WaveGenerator
		{
		public:
			WhiteNoiseGenerator(double inSampleRate, double inFrequency, double inAmplitude);
			virtual void generate(int channels, int samples) override;
			virtual Common::AudioBuffer<float> getBuffer() const override;
		private:
			Common::AudioBuffer<float> Buffer;
		};
	}
}