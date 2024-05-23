#pragma once

#include "LOTEngine/Asset/Asset.h"
#include "LOTEngine/Renderer/Texture2D.h"

#include <memory>

namespace LOT
{
	class TextureAsset : public Asset
	{
	public:
		TextureAsset(const std::string& path);
		static AssetType GetStaticType();
		virtual AssetType GetType() const override;
		virtual bool Reload() override;
		std::shared_ptr<Texture2D> GetTexture();
		const std::string& GetTexturePath() const;

	private:
		std::string m_TexturePath;
		std::shared_ptr<Texture2D> m_Texture;
	};
}
