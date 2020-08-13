#include "sawtoothGenerator.h"
#include <cmath>
#include <limits>

using namespace Orange;
using namespace Orange::Oscillator;


SawtoothGenerator::SawtoothGenerator(double inSampleRate, double inFrequency, double inAmplitude)
	: WaveGenerator(inSampleRate, inFrequency, inAmplitude)
{

}

void SawtoothGenerator::generate(int channels, int samples)
{
	Buffer.allocate(channels, samples);

	//==================================================
	// ここに波形生成を実装
	// とりあえず、ステレオ
	// Buffer.buffer[0]にsamples数のLチャンネルサンプルデータを入れる
	// Buffer.buffer[1]にsamples数のRチャンネルサンプルデータを入れる
	// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	//==================================================
    const double deltatime = 1/sampleRate;
    const double fullPeriodTime = 1/frequency;
    
    if (time >= std::numeric_limits<float>::max()) {
            time = 0.0;
    }
    
    for(int i = 0; i < samples; ++i){
        const double localtime = fmod(time,fullPeriodTime);
        const double value = amplitude * ((localtime / fullPeriodTime) * 2 - 1.0);
        
        Buffer[0][i] = (float)value;
        Buffer[1][i] = (float)value;
        
        time += (float)deltatime;
    }
	//==================================================
	// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
	//==================================================

}

Common::AudioBuffer<float> SawtoothGenerator::getBuffer() const
{
	return Buffer;
}
