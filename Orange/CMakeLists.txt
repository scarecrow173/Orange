if(SMTG_ADD_VSTGUI)
	set(orange_sources
		src/plugin_info.h
		src/plugin_sample.h
		src/plugin_sample.cpp
		src/orange_entry.cpp
		src/waveGenerator.h
		src/waveGenerator.cpp
		src/sineGenerator.h
		src/sineGenerator.cpp
		src/audioBuffer.h
	)

	set(target orange)
	smtg_add_vst3plugin(${target} ${orange_sources})
	set_target_properties(${target} PROPERTIES ${SDK_IDE_MYPLUGINS_FOLDER})
    target_include_directories(${target} PUBLIC ${VSTGUI_ROOT}/vstgui4)
    target_link_libraries(${target} PRIVATE base sdk vstgui_support)

	if(SMTG_MAC)
		smtg_set_bundle(${target} INFOPLIST "${CMAKE_CURRENT_LIST_DIR}/mac/Info.plist" PREPROCESS)
	endif()
endif(SMTG_ADD_VSTGUI)