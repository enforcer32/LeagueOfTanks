#pragma once

#include "LOTEngine/Scene/SceneCamera.h"

namespace LOT
{
	struct CameraComponent
	{
		SceneCamera Camera;
		bool Primary; // What if Multiple Scenes
		double Speed;
		bool Fixed;

		CameraComponent(bool primary = false, double speed = 1.0, bool fixed = false)
			: Primary(primary), Speed(speed), Fixed(fixed)
		{
		}

		CameraComponent(SceneCamera camera, bool primary = false, double speed = 1.0, bool fixed = false)
			: Camera(camera), Primary(primary), Speed(speed), Fixed(fixed)
		{
		}
	};
}
