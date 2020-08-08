#include "sawtoothGenerator.h"
#include <cmath>
#include <limits>

using namespace Orange;
using namespace Orange::Oscillator;


SawtoothGenerator::SawtoothGenerator(double inSampleFrequency, double inFrequency, double inAmplitude)
	: WaveGenerator(inSampleFrequency, inFrequency, inAmplitude)
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
    const double deltatime = 1/sampleFrequency;
    const double fullPeriodTime = 1/frequency;
    
    if (time >= std::numeric_limits<float>::max()) {
            time = 0.0;
    }
    
    for(int i = 0; i < samples; ++i){
        const double localtime = fmod(time,fullPeriodTime);
        const float value = amplitude * ((localtime / fullPeriodTime) * 2 - 1.0);
        
        Buffer.buffer[0][i] = value;
        Buffer.buffer[1][i] = value;
        
        time += deltatime;
    }
	//==================================================
	// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
	//==================================================

}

Common::AudioBuffer SawtoothGenerator::getBuffer() const
{
	return Buffer;
}
