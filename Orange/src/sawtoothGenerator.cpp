#include "sawtoothGenerator.h"
#include <cmath>
#include <limits>

using namespace Orange;
using namespace Orange::Oscillator;


SawtoothGenerator::SawtoothGenerator(double inSampleRate, double inFrequency, double inAmplitude)
	: WaveGenerator(inSampleRate, inFrequency, inAmplitude)
    , time(inSampleRate)
    
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
    const double fullPeriodTime = 1/frequency;
    
    for(int iSample = 0; iSample < samples; ++iSample){
        const double localtime = fmod(time.getElapsedTime(),fullPeriodTime);
        const double value = amplitude * ((localtime / fullPeriodTime) * 2 - 1.0);
        
        for(int iCh = 0; iCh < channels; ++iCh){
            Buffer[iCh][iSample] = (float)value;
        }
        
        time++;
    }
	//==================================================
	// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
	//==================================================

}

Common::AudioBuffer<float> SawtoothGenerator::getBuffer() const
{
	return Buffer;
}
