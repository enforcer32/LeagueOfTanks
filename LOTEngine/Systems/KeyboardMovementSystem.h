#pragma once

#include "LOTEngine/ECS/Registry.h"
#include "LOTEngine/Core/DeltaTime.h"

namespace LOT
{
	class KeyboardMovementSystem : public System
	{
	public:
		KeyboardMovementSystem();

		void OnUpdate(DeltaTime dt);
	};
}
