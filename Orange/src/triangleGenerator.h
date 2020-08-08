#pragma once
#include "waveGenerator.h"
namespace Orange
{
	namespace Oscillator
	{
		class TriangleGenerator : public WaveGenerator
		{
		public:
			TriangleGenerator(double inSampleFrequency, double inFrequency, double inAmplitude);
			virtual void generate(int channels, int samples) override;
			virtual Common::AudioBuffer getBuffer() const override;
		private:
			Common::AudioBuffer Buffer;
		};
	}
}