#include "sineGenerator.h"
#include <cmath>
#include "base/source/fstring.h"

#ifndef M_PI
#define M_PI			3.14159265358979323846
#endif
#ifndef M_PI_MUL_2
#define M_PI_MUL_2		6.28318530717958647692
#endif

using namespace Orange;
using namespace Orange::Oscillator;


SineGenerator::SineGenerator(double inSampleFrequency, double inFrequency, double inAmplitude)
	: WaveGenerator(inSampleFrequency, inFrequency, inAmplitude)
{

}

void SineGenerator::generate(int channels, int samples)
{
	Buffer.allocate(channels, samples);

	//==================================================
	// ここにサイン波の生成を実装
	// とりあえず、ステレオ
	// Buffer.buffer[0]にsamples数のLチャンネルサンプルデータを入れる
	// Buffer.buffer[1]にsamples数のRチャンネルサンプルデータを入れる
	// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	//==================================================
    const float deltatime = 1/sampleFrequency;
    
    if (time >= std::numeric_limits<float>::max()) {
            time = 0.0;
    }
    
    for(int i = 0; i < samples; ++i){
        const float value = amplitude * sin(M_PI_MUL_2 * frequency * time + phase);
        
        Buffer.buffer[0][i] = value;
        Buffer.buffer[1][i] = value;
        
        time += deltatime;
    }
	//==================================================
	// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
	//==================================================

}

Common::AudioBuffer SineGenerator::getBuffer() const
{
	return Buffer;
}

