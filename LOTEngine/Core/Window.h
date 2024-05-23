#pragma once

#include <string>

namespace LOT
{
	struct WindowProperties
	{
		std::string Name;
		uint32_t Width;
		uint32_t Height;
		bool VSync;
	};

	class Window
	{
	public:
		Window();

		bool Init(const WindowProperties& props);
		void Destroy();
		void Update();
		
		const WindowProperties& GetProperties() const;
		void SetProperties(const WindowProperties& props);
		bool IsVSync() const;
		void SetVSync(bool vsync);
		uint32_t GetWidth() const;
		uint32_t GetHeight() const;
		inline const auto* GetNativeWindow() const { return m_NativeWindow; }

	private:
		bool InitContext();

	private:
		struct WindowPrivateData
		{
			std::string Name;
			uint32_t Width;
			uint32_t Height;
			bool VSync;
		};

		bool m_Initialized;
		void* m_NativeWindow;
		WindowPrivateData m_WinPrivData;
	};
}
