#pragma once
#include "audioBuffer.h"

namespace Orange
{
	namespace Oscillator 
	{
		class WaveGenerator
		{
		public:
			WaveGenerator(double inSampleRate, double inFrequency, double inAmplitude);
			virtual ~WaveGenerator();

			virtual void generate(int channels, int samples) = 0;
			virtual Common::AudioBuffer<float> getBuffer() const = 0;

			void setSampleRate(const double inSampleRate) { sampleRate = inSampleRate; };
			void setFrequency(const double inFrequency) { frequency = inFrequency; }
			void setAmplitude(const double inAmplitude) { amplitude = inAmplitude; }
			void setPhase(const double inPhase) { phase = inPhase; }

			double getsampleRate() const { return sampleRate; }
			double getFrequency() const { return frequency; }
			double getAmplitude() const { return amplitude; }
			double getPhase() const { return phase; }

		protected:
			double sampleRate = 0.0;
			double frequency = 0.0;
			double amplitude = 1.0;
			double phase = 1.0;

		};
	}

}