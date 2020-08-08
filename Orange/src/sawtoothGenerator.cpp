#include "sawtoothGenerator.h"
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

	//==================================================
	// ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
	//==================================================

}

Common::AudioBuffer SawtoothGenerator::getBuffer() const
{
	return Buffer;
}