﻿#pragma once

#include <string.h>

namespace Orange
{
	namespace Common
	{
		struct AudioBuffer
		{
			AudioBuffer() : numChannels(0), numSamples(0), buffer(0)
			{

			}

			inline void allocate(int channels, int samples)
			{
				if (channels == numChannels && channels > 0
					&& samples == numSamples && samples > 0)
				{
					for (size_t iChannels = 0; iChannels < channels; iChannels++)
					{
						 memset(buffer[iChannels], 0, (size_t)samples);
					}
				}
				else
				{
					clear();
					numChannels = channels;
					numSamples = samples;
					buffer = new float*[channels];
					for (size_t iChannels = 0; iChannels < channels; iChannels++)
					{
						if (samples > 0)
							buffer[iChannels] = new float[samples];
						else
							buffer[iChannels] = nullptr;
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
							delete buffer[iChannels];
							buffer[iChannels] = nullptr;
						}
					}
					delete buffer;
					buffer = nullptr;
				}
			}

			int numChannels = 0;
			int numSamples = 0;
			float** buffer;
		};
	}
}