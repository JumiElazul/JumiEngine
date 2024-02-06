project "JumiSandbox"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   dependson "EngineCore"

   files 
   {
       "src/**.cpp",
       "src/**.h",
   }

   includedirs 
   {
       "src",
       "../vcpkg_installed/%{triplet}/include",
       "../EngineCore/include",
   }

   filter "system:windows"
       defines { "JUMI_WINDOWS", "_CRT_SECURE_NO_WARNINGS" }
       warnings "Extra"

   filter "configurations:Debug"
       symbols "On"
       libdirs 
       {
           "../EngineCore/bin/Debug",
           "../vcpkg_installed/%{triplet}/debug/lib",
       }
       links { "EngineCore-debug" }

   filter "configurations:Release"
       optimize "On"
       libdirs 
       {
           "../EngineCore/bin/Release",
           "../vcpkg_installed/%{triplet}/lib",
       }
       links { "EngineCore-release" }
