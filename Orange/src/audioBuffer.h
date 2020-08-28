#pragma once

#include <string.h>

namespace Orange
{
	namespace Common
	{
		template<typename T> struct AudioBuffer
		{
			AudioBuffer() : numChannels(0), numSamples(0), buffer(0)
			{

			}
			AudioBuffer(const int inNumChannles, const int inNumSamples) : numChannels(inNumChannles), numSamples(inNumSamples), buffer(0)
			{
				allocate(inNumChannles, inNumSamples);
			}
			AudioBuffer(const AudioBuffer& other) : numChannels(other.numChannels), numSamples(other.numSamples), buffer(0)
			{
				allocate(numChannels, numSamples);
				for (size_t iChannels = 0; iChannels < numChannels; iChannels++)
				{
					memcpy(buffer[iChannels], other.buffer[iChannels], (size_t)numSamples * sizeof(T));
				}

			}
			inline void allocate(int channels, int samples)
			{
				if (channels == numChannels && channels > 0
					&& samples == numSamples && samples > 0
					&& buffer != nullptr)
				{
					for (size_t iChannels = 0; iChannels < channels; iChannels++)
					{
						if (buffer[iChannels] == nullptr)
						{
							buffer[iChannels] = new T[samples];
							memset(buffer[iChannels], 0, (size_t)samples * sizeof(T));
						}
						else
						{
							memset(buffer[iChannels], 0, (size_t)samples * sizeof(T));
						}
					}
				}
				else
				{
					clear();
					numChannels = channels;
					numSamples = samples;
					buffer = new T*[channels];
					for (size_t iChannels = 0; iChannels < channels; iChannels++)
					{
						if (samples > 0)
						{
							buffer[iChannels] = new T[samples];
							memset(buffer[iChannels], 0, (size_t)samples * sizeof(T));
						}
						else
						{
							buffer[iChannels] = nullptr;
						}
					}
				}
			}
			
			inline void clear()
			{
				if (buffer != nullptr)
				{
					for (size_t iChannels = 0; iChannels < numChannels; iChannels++)
					{
						if (numSamples > 0)
						{
							delete[] buffer[iChannels];
							buffer[iChannels] = nullptr;
						}
					}
					delete[] buffer;
					buffer = nullptr;
				}
			}

			inline int getChannels() const
			{
				return numChannels;
			}

			inline int getSamples() const
			{
				return numChannels;
			}
			inline bool isValidIndex(const int idx)
			{
				return idx >= 0 && idx < numSamples;
			}
			//==================================================
			// operators
			//==================================================
			inline T* operator[](short idx)
			{
				if (!isValidIndex(idx))
				{
					return nullptr;
				}
				return buffer[idx];
			}
			inline T* operator[](long idx)
			{
				if (!isValidIndex(idx))
				{
					return nullptr;
				}
				return buffer[idx];
			}
			inline T* operator[](int idx)
			{
				if (!isValidIndex(idx))
				{
					return nullptr;
				}
				return buffer[idx];
			}
			inline T* operator[](unsigned short idx)
			{
				if (!isValidIndex(idx))
				{
					return nullptr;
				}
				return buffer[idx];
			}
			inline T* operator[](unsigned long idx)
			{
				if (!isValidIndex(idx))
				{
					return nullptr;
				}
				return buffer[idx];
			}
			inline T* operator[](unsigned int idx)
			{
				if (!isValidIndex(idx))
				{
					return nullptr;
				}
				return buffer[idx];
			}
		private:
			int numChannels = 0;
			int numSamples = 0;
			T** buffer;

		};
	}
}