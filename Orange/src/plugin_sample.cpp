#include "plugin_sample.h"
#include "sineGenerator.h"

using namespace Steinberg;
using namespace Steinberg::Vst;
using namespace Orange::Plugin;


//==================================================
// Effect
//==================================================
SamplePluginEffect::SamplePluginEffect()
	: AudioEffect()
{
	setControllerClass(ORANGE_SAMPLE_PLUGIN_CONTROLLER_UID);
}

SamplePluginEffect::~SamplePluginEffect()
{
}

tresult PLUGIN_API SamplePluginEffect::initialize(FUnknown* context)
{
	tresult result = AudioEffect::initialize(context);
	if (result == kResultTrue)
	{
		addAudioInput(STR16("AudioInput"), SpeakerArr::kStereo);
		addAudioOutput(STR16("AudioOutput"), SpeakerArr::kStereo);
	}


	return result;
}

tresult PLUGIN_API SamplePluginEffect::terminate()
{
	// nothing to do here yet...except calling our parent terminate
	return AudioEffect::terminate();
}

tresult PLUGIN_API SamplePluginEffect::setBusArrangements(SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts)
{
	if (numIns == 1 && numOuts == 1 && inputs[0] == SpeakerArr::kStereo && outputs[0] == SpeakerArr::kStereo)
	{
		return AudioEffect::setBusArrangements(inputs, numIns, outputs, numOuts);
	}

	return kResultFalse;
}

tresult PLUGIN_API SamplePluginEffect::process(Steinberg::Vst::ProcessData& data)
{

	if (data.inputParameterChanges != NULL)
	{
		int32 paramChangeCount = data.inputParameterChanges->getParameterCount();

		for (int32 i = 0; i < paramChangeCount; i++)
		{
			IParamValueQueue* queue = data.inputParameterChanges->getParameterData(i);
			if (queue != NULL)
			{
				int32 tag = queue->getParameterId();

				int32 valueChangeCount = queue->getPointCount();
				ParamValue value;
				int32 sampleOffset;

				if (queue->getPoint(valueChangeCount - 1, sampleOffset, value) == kResultTrue)
				{
					switch (tag)
					{
					case ORANGE_SAMPLE_PLUGIN_CONTROLLER_SAMPLEFREQ_TAG:
						sampleFreq = value;
						break;
					case ORANGE_SAMPLE_PLUGIN_CONTROLLER_FREQ_TAG:
						freq = value;
						break;
					}
				}
			}
		}
	}

	if (data.numInputs == 0 || data.numOutputs == 0)
	{
		// nothing to do
		return kResultOk;
	}

	Sample32* inL = data.inputs[0].channelBuffers32[0];
	Sample32* inR = data.inputs[0].channelBuffers32[1];
	Sample32* outL = data.outputs[0].channelBuffers32[0];
	Sample32* outR = data.outputs[0].channelBuffers32[1];

	if (data.inputs[0].silenceFlags == 0)
	{
		Orange::Oscillator::SineGenerator SineOsc(getSampleRate() * sampleFreq, getSampleRate() * 0.5 * freq, 32.0);
		SineOsc.generate(data.outputs->numChannels, data.numSamples);
		Orange::Common::AudioBuffer Buffer = SineOsc.getBuffer();
		for (int32 i = 0; i < data.numSamples; i++)
		{
			outL[i] = Buffer.buffer[0][i];
			outR[i] = Buffer.buffer[1][i];
		}
	}
	else
	{
		for (int32 i = 0; i < data.numSamples; i++)
		{
			outL[i] = inL[i];
			outR[i] = inR[i];
		}
	}
	data.outputs[0].silenceFlags = 0;

	return kResultTrue;
}

//==================================================
// Controller
//==================================================
SamplePluginController::SamplePluginController()
	: EditController()
{

}
SamplePluginController::~SamplePluginController()
{

}

tresult PLUGIN_API SamplePluginController::initialize(FUnknown* context)
{
	tresult result = EditController::initialize(context);
	if (result == kResultTrue)
	{
		parameters.addParameter(STR16("SampleFreq"), STR16("..."), 0, 1, ParameterInfo::kCanAutomate, ORANGE_SAMPLE_PLUGIN_CONTROLLER_SAMPLEFREQ_TAG);
		parameters.addParameter(STR16("Freq"), STR16("..."), 0, 1, ParameterInfo::kCanAutomate, ORANGE_SAMPLE_PLUGIN_CONTROLLER_FREQ_TAG);
	}

	result = kResultTrue;
	return result;
}

tresult PLUGIN_API SamplePluginController::terminate()
{
	return EditController::terminate();
}



