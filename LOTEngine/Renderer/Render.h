#pragma once

#include "LOTEngine/Renderer/VertexArray.h"

namespace LOT
{
	class Render
	{
	public:
		static void DrawIndexed(uint32_t drawMode, const VertexArray& va, uint32_t count = 0);
	};
}
