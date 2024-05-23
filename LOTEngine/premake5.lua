project "LOTEngine"
kind "StaticLib"
language "C++"
cppdialect "C++17"
staticruntime "off"

targetdir ("%{wks.location}/Build/" .. outputdir .. "/%{prj.name}")
objdir ("%{wks.location}/Build/Intermediates/" .. outputdir .. "/%{prj.name}")

pchheader "LOTEnginePCH.h"
pchsource "LOTEnginePCH.cpp"

files
{
	"**.h",
	"**.cpp",
	"%{wks.location}/Dependencies/glm/glm/**.hpp",
	"%{wks.location}/Dependencies/glm/glm/**.inl",
	"%{wks.location}/Dependencies/fnv/fnv/**.h",
}

excludes
{
}

defines
{
	"LOT_ENGINE",
}

includedirs
{
	"%{wks.location}",
	"%{wks.location}/LOTEngine",
	"%{IncludeDir.spdlog}",
	"%{IncludeDir.glm}",
	"%{IncludeDir.fnv}",
}

links
{
	"spdlog",
}

filter "system:windows"
	systemversion "latest"

	defines
	{
		"LOT_PLATFORM_WINDOWS",
	}

	files
	{
	}

filter "configurations:Debug"
	defines "LOT_ENGINE_DEBUG"
	runtime "Debug"
	symbols "On"

filter "configurations:Release"
	defines "LOT_ENGINE_RELEASE"
	runtime "Release"
	optimize "On"
