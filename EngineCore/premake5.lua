project "EngineCore"
   kind "StaticLib"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files 
   {
       "src/**.cpp",
       "src/**.h",
   }

   includedirs
   {
       "src",
       "include",
       "../vcpkg_installed/%{triplet}/include"
   }

   defines { "GLFW_INCLUDE_NONE" }

   filter "system:windows"
       defines { "JUMI_WINDOWS", "_CRT_SECURE_NO_WARNINGS" }

   filter "configurations:Debug"
      symbols "On"
      targetname "EngineCore-debug"
      libdirs 
      {
          "../vcpkg_installed/%{triplet}/debug/lib",
      }
      links { "fmtd", "glfw3", "glad" }

   filter "configurations:Release"
      optimize "On"
      targetname "EngineCore-release"
      libdirs 
      {
          "../vcpkg_installed/%{triplet}/lib" 
      }
      links { "fmt", "glfw3", "glad" }
