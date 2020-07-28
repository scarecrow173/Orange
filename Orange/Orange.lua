project "Orange"
    location "./"
    kind "SharedLib"
    language "C++"
    targetextension ".vst3"
    files {
        "**.c",
        "**.cpp",
        "**.cc",
        "**.h",
        "**.hpp",
        "vst3.def" 
    }
    excludes{
        "obj/**",
        "Tests/**"
    }
    includedirs {
        "include",
        "../dependencies/vstsdk/",
        "../dependencies/vstsdk/vstgui4"
        
    }
    
    defines { 
        "VSTGUI_LIVE_EDITING=1"
    }

    -- Setting Windows x86 Debug Optins
    filter { "platforms:x86", "configurations:Debug" }
        libdirs  {
            "../build/x86/lib/Debug"
        }

    -- Setting Windows x86 Release Optins
    filter { "platforms:x86", "configurations:Release" }
        libdirs  {
            "../build/x86/lib/Release"
        }
    
    -- Setting Windows x64 Debug Optins
    filter { "platforms:x64", "configurations:Debug" }
        libdirs  {
            "../build/x64/lib/Debug"
        }
    
    -- Setting Windows x64 Release Optins
    filter { "platforms:x64", "configurations:Release" }
        libdirs  {
            "../build/x64/lib/Release"
        }
    
    -- Setting Windows Platform Optins
    filter { "platforms:x86 or x64"}
        links {
            "base",
            "sdk",
            "pluginterfaces",
            "vstgui",
            "vstgui_support",
            "vstgui_uidescription"
        }
        defines { 
            "_WINDOWS",
            "Orange_EXPORTS"
        }
        files {
            "../dependencies/vstsdk/public.sdk/source/main/dllmain.cpp"
        }
        

    -- Setting Debug Optins
    filter { "configurations:Debug" }
        defines { 
            "_DEBUG",
            "DEBUG",
            "DEVELOPMENT=1"
        }
        symbols "On"

    -- Setting Release Optins
    filter { "configurations:Release" }
        defines { "NDEBUG" }
        optimize "Full"