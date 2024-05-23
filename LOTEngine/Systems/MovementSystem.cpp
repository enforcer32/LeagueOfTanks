#include "LOTEnginePCH.h
#include "LOTEngine/Systems/MovementSystem.h"
#include "LOTEngine/Components/TransformComponent.h"
#include "LOTEngine/Components/RigidBodyComponent.h"

namespace LOT
{
	MovementSystem::MovementSystem()
	{
		RegisterComponent<TransformComponent>();
		RegisterComponent<RigidBodyComponent>();
	}

	void MovementSystem::OnUpdate(DeltaTime dt)
	{
		for (auto& entity : GetEntities())
		{
			auto& transform = entity.GetComponent<TransformComponent>();
			const auto& rigidbody = entity.GetComponent<RigidBodyComponent>();
			transform.Translation += rigidbody.Velocity * (float)dt;
		}
	}
}
