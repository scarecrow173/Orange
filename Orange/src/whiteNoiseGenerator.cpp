#include "whiteNoiseGenerator.h"
using namespace Orange;
using namespace Orange::Oscillator;


WhiteNoiseGenerator::WhiteNoiseGenerator(double inSampleRate, double inFrequency, double inAmplitude)
	: WaveGenerator(inSampleRate, inFrequency, inAmplitude)
{

}

void WhiteNoiseGenerator::generate(int channels, int samples)
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

Common::AudioBuffer<float> WhiteNoiseGenerator::getBuffer() const
{
	return Buffer;
}