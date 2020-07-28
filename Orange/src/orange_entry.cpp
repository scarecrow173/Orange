#include "public.sdk/source/main/pluginfactory.h"
#include "public.sdk/source/vst/vstaudioeffect.h"
#include "pluginterfaces/base/funknown.h"
#include "plugin_info.h"
#include "plugin_sample.h"

//==================================================
// DLLファイルの初期化、終了処理関数
//==================================================
bool InitModule() { return true; }
bool DeinitModule() { return true; }


//==================================================
// プラグインの生成
//==================================================
BEGIN_FACTORY(ORANGE_PLUGIN_VENDOR_NAME, ORANGE_PLUGIN_URL, ORANGE_PLUGIN_MAIL, PFactoryInfo::kNoFlags)

	DEF_CLASS2(INLINE_UID_FROM_FUID(ORANGE_SAMPLE_PLUGIN_EFFECT_UID),
		ORANGE_SAMPLE_PLUGIN_EFFECT_CARDINALITY,
		kVstAudioEffectClass,
		ORANGE_SAMPLE_PLUGIN_NAME,
		ORANGE_SAMPLE_PLUGIN_EFFECT_FLAGS,
		ORANGE_SAMPLE_PLUGIN_EFFECT_SUBCATEGORY,
		ORANGE_SAMPLE_PLUGIN_VERSION,
		kVstVersionString,
		SamplePluginEffect::createInstance)

	DEF_CLASS2(INLINE_UID_FROM_FUID(ORANGE_SAMPLE_PLUGIN_CONTROLLER_UID),
		ORANGE_SAMPLE_PLUGIN_CONTROLLER_CARDINALITY,
		kVstComponentControllerClass,
		ORANGE_SAMPLE_PLUGIN_CONTROLLER_NAME,
		ORANGE_SAMPLE_PLUGIN_CONTROLLER_FLAGS,
		ORANGE_SAMPLE_PLUGIN_CONTROLLER_SUBCATEGORY,
		ORANGE_SAMPLE_PLUGIN_VERSION,
		kVstVersionString,
		SamplePluginController::createInstance)

END_FACTORY
