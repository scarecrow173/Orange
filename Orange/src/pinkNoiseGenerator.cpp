﻿#include "PinkNoiseGenerator.h"
using namespace Orange;
using namespace Orange::Oscillator;


PinkNoiseGenerator::PinkNoiseGenerator(double inSampleFrequency, double inFrequency, double inAmplitude)
	: WaveGenerator(inSampleFrequency, inFrequency, inAmplitude)
{

}

void PinkNoiseGenerator::generate(int channels, int samples)
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

Common::AudioBuffer PinkNoiseGenerator::getBuffer() const
{
	return Buffer;
}