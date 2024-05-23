#pragma once

#include "LOTEngine/Core/Logger.h"

#if defined LOT_DEBUG || LOT_ENGINE_DEBUG
	#ifdef LOT_PLATFORM_WINDOWS
		#define LOT_DEBUGBREAK() __debugbreak()	
	#else
		#error "Platform doesnt support debugbreak"
	#endif

	#define LOT_ENABLE_ASSERTS
#else
	#define LOT_DEBUGBREAK()
#endif


#ifdef LOT_ENABLE_ASSERTS
	#define LOT_ASSERT(x, msg) { if(!(x)) { LOT_LOG_ERROR("Assertion Error: {}, File: {}, Line: {}", msg, __FILE__, __LINE__); LOT_DEBUGBREAK(); } }
#else
	#define LOT_ASSERT(...)
#endif
