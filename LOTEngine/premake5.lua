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
	"%{IncludeDir.sfml}",
}

links
{
	"spdlog",

	"%{wks.location}/Dependencies/SFML/lib/flac.lib",
	"%{wks.location}/Dependencies/SFML/lib/freetype.lib",
	"%{wks.location}/Dependencies/SFML/lib/ogg.lib",
	"%{wks.location}/Dependencies/SFML/lib/openal32.lib",
	"%{wks.location}/Dependencies/SFML/lib/vorbis.lib",
	"%{wks.location}/Dependencies/SFML/lib/vorbisenc.lib",
	"%{wks.location}/Dependencies/SFML/lib/vorbisfile.lib",

	"%{wks.location}/Dependencies/SFML/lib/sfml-audio.lib",
	"%{wks.location}/Dependencies/SFML/lib/sfml-graphics.lib",
	"%{wks.location}/Dependencies/SFML/lib/sfml-network.lib",
	"%{wks.location}/Dependencies/SFML/lib/sfml-system.lib",
	"%{wks.location}/Dependencies/SFML/lib/sfml-window.lib",
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
