#pragma once

#include "LOTEngine/ECS/Registry.h"
#include "LOTEngine/Core/DeltaTime.h"

namespace LOT
{
	class CameraControlSystem : public System
	{
	public:
		CameraControlSystem();

		void OnUpdate(DeltaTime dt);
	};
}
