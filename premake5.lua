workspace "CodeByte"
	architecture "x86_64"
	startproject "SandBox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Core"
	include "CodeByteEngine"
	include "CodeByteMath"
group ""

group "Misc"
	include "SandBox"
group ""	