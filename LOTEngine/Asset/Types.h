#pragma once

#include "LOTEngine/Core/UUID.h"

namespace LOT
{
	using AssetID = UUID;

	enum class AssetType
	{
		None,
		Texture,
		Spritesheet
	};

	enum class AssetFlag
	{
		Invalid,
		Missing,
		Unloaded,
		Loaded,
	};
}
