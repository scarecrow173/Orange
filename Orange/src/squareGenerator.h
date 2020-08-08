#pragma once
#include "waveGenerator.h"
namespace Orange
{
	namespace Oscillator
	{
		class SquareGenerator : public WaveGenerator
		{
		public:
			SquareGenerator(double inSampleFrequency, double inFrequency, double inAmplitude);
			virtual void generate(int channels, int samples) override;
			virtual Common::AudioBuffer getBuffer() const override;
		private:
			Common::AudioBuffer Buffer;
		};
	}
}