#pragma once

#include "LOTEngine/ECS/Registry.h"
#include "LOTEngine/Core/DeltaTime.h"
#include "LOTEngine/Renderer/Renderer2D.h"

#include <memory>

namespace LOT
{
	class RenderSystem : public System
	{
	public:
		RenderSystem();

		void OnUpdate(DeltaTime dt, const std::shared_ptr<Renderer2D>& renderer);
	};
}
