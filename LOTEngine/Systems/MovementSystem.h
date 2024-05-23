#pragma once

#include "LOTEngine/ECS/Registry.h"
#include "LOTEngine/Core/DeltaTime.h"

namespace LOT
{
	class MovementSystem : public System
	{
	public:
		MovementSystem();

		void OnUpdate(DeltaTime dt);
	};
}
