local config_list = {
    "Release",
    "Debug",
}
local platform_list = {
    "x86",
    "x64",
    "macosx",
    "linux"
}
workspace "Orange"
    platforms(platform_list)
    configurations(config_list)

    -- Setting visual studio Optins
    filter { "action:vs*" }
    
    -- Setting xcode Optins
    filter { "action:xcode" }
        xcodebuildsettings {
            ["CLANG_CXX_LANGUAGE_STANDARD"] = "c++14";
        }

    -- Setting gmake Optins
    filter { "action:gmake*" }
        buildoptions {"-std=c++14"}

        dofile("Orange/Orange.lua")