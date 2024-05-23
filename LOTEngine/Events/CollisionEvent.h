#pragma once

#include "LOTEngine/Events/Event.h"
#include "LOTEngine/ECS/Registry.h"

namespace LOT
{
	class CollisionEvent : public Event
	{
	public:
		Entity entityA;
		Entity entityB;

		CollisionEvent(Entity a, Entity b)
			: entityA(a), entityB(b) {}
	};
}
