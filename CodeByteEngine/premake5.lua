project "CodeByteEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"**.h",
		"**.cpp"
	}
	
	links
	{
		"d3d11.lib",
		"d3dcompiler.lib"
	}



	filter "system:windows"
		systemversion "latest"


	filter "configurations:Debug"
		defines "CB_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CB_RELEASE"
		runtime "Release"
		optimize "on"


	filter "configurations:Dist"
		defines "CB_DIST"
		runtime "Release"
		optimize "on"