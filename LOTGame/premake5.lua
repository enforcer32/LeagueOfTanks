project "LOTGame"
kind "ConsoleApp"
language "C++"
cppdialect "C++17"
staticruntime "off"

targetdir ("%{wks.location}/Build/" .. outputdir .. "/%{prj.name}")
objdir ("%{wks.location}/Build/Intermediates/" .. outputdir .. "/%{prj.name}")

pchheader "LOTGamePCH.h"
pchsource "LOTGamePCH.cpp"

files
{
	"**.h",
	"**.cpp",
}

includedirs
{
	"%{wks.location}",
	"%{IncludeDir.spdlog}",
	"%{IncludeDir.glm}",
}

links
{
	"LOTEngine"
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
	defines "LOT_DEBUG"
	runtime "Debug"
	symbols "On"

filter "configurations:Release"
	defines "LOT_RELEASE"
	runtime "Release"
	optimize "On"
