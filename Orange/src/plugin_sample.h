#pragma once
#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"
#include "pluginterfaces/vst/ivstaudioprocessor.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include "public.sdk/source/vst/vstaudioeffect.h"
#include "public.sdk/source/vst/vsteditcontroller.h"

static const Steinberg::Vst::CString					ORANGE_SAMPLE_PLUGIN_VERSION = "0.1";
static const Steinberg::Vst::CString					ORANGE_SAMPLE_PLUGIN_NAME = "Sample Effect";
static const Steinberg::Vst::CString					ORANGE_SAMPLE_PLUGIN_EFFECT_NAME = "Sample Effect";
static const Steinberg::Vst::CString					ORANGE_SAMPLE_PLUGIN_EFFECT_SUBCATEGORY = Steinberg::Vst::PlugType::kFx;
static const Steinberg::PClassInfo::ClassCardinality	ORANGE_SAMPLE_PLUGIN_EFFECT_CARDINALITY = Steinberg::PClassInfo::kManyInstances;
static const Steinberg::int32							ORANGE_SAMPLE_PLUGIN_EFFECT_FLAGS = Steinberg::Vst::kDistributable;
static const Steinberg::FUID							ORANGE_SAMPLE_PLUGIN_EFFECT_UID(0xF58E9FCC, 0x09BA4678, 0x94E76CE0, 0xD24535C1);

static const Steinberg::Vst::CString					ORANGE_SAMPLE_PLUGIN_CONTROLLER_NAME = "Sample Effect Controller";
static const Steinberg::Vst::CString					ORANGE_SAMPLE_PLUGIN_CONTROLLER_SUBCATEGORY = "";
static const Steinberg::PClassInfo::ClassCardinality	ORANGE_SAMPLE_PLUGIN_CONTROLLER_CARDINALITY = Steinberg::PClassInfo::kManyInstances;
static const Steinberg::int32							ORANGE_SAMPLE_PLUGIN_CONTROLLER_FLAGS = 0;
static const Steinberg::FUID							ORANGE_SAMPLE_PLUGIN_CONTROLLER_UID(0x17D73226, 0xC2AA4000, 0xA20B7970, 0x21728B3E);

static const int										ORANGE_SAMPLE_PLUGIN_CONTROLLER_PARAM1_TAG = 100;

class SamplePluginEffect : public Steinberg::Vst::AudioEffect
{
public:
	SamplePluginEffect();
	virtual ~SamplePluginEffect();

	//--- ---------------------------------------------------------------------
	// create function required for Plug-in factory,
	// it will be called to create new instances of this Plug-in
	//--- ---------------------------------------------------------------------
	static Steinberg::FUnknown* createInstance(void* /*context*/) { return (Steinberg::Vst::IAudioProcessor*)new SamplePluginEffect; }

	/** Called at first after constructor */
	Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) SMTG_OVERRIDE;

	/** Called at the end before destructor */
	Steinberg::tresult PLUGIN_API terminate() SMTG_OVERRIDE;

	/** Here we go...the process call */
	Steinberg::tresult PLUGIN_API process(Steinberg::Vst::ProcessData& data) SMTG_OVERRIDE;

	/** Bus arrangement managing: in this example the 'again' will be mono for mono input/output and
	 * stereo for other arrangements. */
	Steinberg::tresult PLUGIN_API setBusArrangements(Steinberg::Vst::SpeakerArrangement* inputs, Steinberg::int32 numIns,
		Steinberg::Vst::SpeakerArrangement* outputs,
		Steinberg::int32 numOuts) SMTG_OVERRIDE;


	Steinberg::Vst::ParamValue volume = 0.0;
private:

};

class SamplePluginController : public Steinberg::Vst::EditController
{
public:
	SamplePluginController();
	virtual ~SamplePluginController();

	//--- ---------------------------------------------------------------------
	// create function required for Plug-in factory,
	// it will be called to create new instances of this controller
	//--- ---------------------------------------------------------------------
	static Steinberg::FUnknown* createInstance(void* /*context*/)
	{
		return (Steinberg::Vst::IEditController*)new SamplePluginController;
	}

	//---from IPluginBase--------
	Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) SMTG_OVERRIDE;
	Steinberg::tresult PLUGIN_API terminate() SMTG_OVERRIDE;

private:
};



