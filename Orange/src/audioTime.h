#pragma once

#include <limits>
#include <cmath>
#include <float.h>


namespace Orange
{
	namespace Common
	{
		struct AudioTime
		{
		public:
			AudioTime(const double inSampleRate) : sampleRate(inSampleRate)
			{
				deltaTime = 1.0 / inSampleRate;

			}

			inline void reset()
			{
				elapsedTime = 0.0;
			}

			inline double forwardSampleTime()
			{
				elapsedTime += deltaTime;
				if (elapsedTime >= std::numeric_limits<double>::max()) {
					elapsedTime = 0.0;
				}
				return elapsedTime;
			}

			inline double forwardSampleTime(const int samples)
			{
				for (int i = 0; i < samples; ++i) {
					forwardSampleTime();
				}
				return elapsedTime;
			}

			inline double backwardSampleTime()
			{
				elapsedTime -= deltaTime;
				if (elapsedTime < 0.0) {
					elapsedTime = 0.0;
				}
				return elapsedTime;
			}

			inline double backwardSampleTime(const int samples)
			{
				for (int i = 0; i < samples; ++i) {
					backwardSampleTime();
				}
				return elapsedTime;
			}

			inline int getSampleCount()
			{
				return elapsedTime / deltaTime;
			}

			inline void setSampleRate(const double inSampleRate)
			{
				sampleRate = inSampleRate;
				deltaTime = 1.0 / inSampleRate;
			}

			inline double getSampleRate() const
			{
				return sampleRate;
			}

			inline double getElapsedTime() const
			{
				return elapsedTime;
			}

			inline double getDeltaTime() const
			{
				return deltaTime;
			}

			//==================================================
			// operators
			//==================================================
			inline AudioTime& operator++()
			{
				forwardSampleTime();
				return *this;
			}

			inline AudioTime& operator--()
			{
				backwardSampleTime();
				return *this;
			}

			inline AudioTime& operator+(const double other)
			{
				AudioTime result(sampleRate);
				result += other;
				return result;
			}

			inline AudioTime& operator+(const AudioTime& other)
			{
				AudioTime result(sampleRate);
				result += other.elapsedTime;
				return result;
			}

			inline AudioTime& operator-(const double other)
			{
				AudioTime result(sampleRate);
				result -= other;
				return result;
			}

			inline AudioTime& operator-(const AudioTime& other)
			{
				AudioTime result(sampleRate);
				result -= other.elapsedTime;
				return result;
			}

			inline AudioTime& operator+=(const double other)
			{
				elapsedTime += other;
				if (elapsedTime >= std::numeric_limits<double>::max()) {
					elapsedTime = 0.0;
				}
				return *this;
			}

			inline AudioTime& operator+=(const AudioTime& other)
			{
				*this += other.elapsedTime;
				return *this;
			}

			inline AudioTime& operator-=(const double other)
			{
				elapsedTime -= other;
				if (elapsedTime < 0.0) {
					elapsedTime = 0.0;
				}
				return *this;
			}

			inline AudioTime& operator-=(const AudioTime& other)
			{
				*this -= other.elapsedTime;
				return *this;
			}

			inline bool operator<(const double other)
			{
				return elapsedTime < other;
			}

			inline bool operator<(const AudioTime& other)
			{
				return *this < other.elapsedTime;
			}

			inline bool operator<=(const double other)
			{
				return elapsedTime <= other;
			}

			inline bool operator<=(const AudioTime& other)
			{
				return *this <= other.elapsedTime;
			}

			inline bool operator>(const double other)
			{
				return elapsedTime > other;
			}
			inline bool operator>(const AudioTime& other)
			{
				return *this > other.elapsedTime;
			}

			inline bool operator>=(const double other)
			{
				return elapsedTime >= other;
			}
			inline bool operator>=(const AudioTime& other)
			{
				return *this >= other.elapsedTime;
			}

			inline bool operator==(const double other)
			{
				return fabs(elapsedTime - other) < DBL_EPSILON;
			}
			inline bool operator==(const AudioTime& other)
			{
				return *this == other.elapsedTime;
			}

			inline bool operator!=(const double other)
			{
				return fabs(elapsedTime - other) >= DBL_EPSILON;
			}
			inline bool operator!=(const AudioTime& other)
			{
				return *this != other.elapsedTime;
			}

		private:
			double deltaTime = 0.0;
			double elapsedTime = 0.0;
			double sampleRate = 0.0;

		};
	}
}