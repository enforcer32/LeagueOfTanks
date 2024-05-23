include "Dependencies.lua"

workspace "LeagueOfTanks"
	architecture "x64"
	startproject "LOTGame"
	configurations { "Debug", "Release" }

outputdir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

group "Dependencies"
	include "Dependencies/spdlog"
group ""

include "LOTEngine"
include "LOTGame"
