#include "LOTEnginePCH.h
#include "LOTEngine/Renderer/Render.h"

#include <glad/glad.h>

namespace LOT
{
	void Render::DrawIndexed(uint32_t drawMode, const VertexArray& va, uint32_t count)
	{
		va.Bind();
		glDrawElements(drawMode, count == 0 ? va.GetIndexBuffer()->GetSize() : count, GL_UNSIGNED_INT, nullptr);
	}
}
