#pragma once

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <utility>
#include <vector>
#include <array>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <fnv/fnv.h>

#ifdef LOT_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
