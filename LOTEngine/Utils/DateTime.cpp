#include "LOTEnginePCH.h
#include "Utils/DateTime.h"

#include <GLFW/glfw3.h>

namespace LOT
{
	double DateTime::GetTimeSeconds()
	{
		return glfwGetTime();
	}

	double DateTime::GetTimeMilliSeconds()
	{
		return glfwGetTime() * 1000;
	}
}
