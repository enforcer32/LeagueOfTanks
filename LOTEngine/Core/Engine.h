#pragma once

#include "LOTEngine/Core/Window.h"
#include "LOTEngine/Core/DeltaTime.h"

#include <memory>

namespace LOT
{
	struct EngineProperties
	{
		WindowProperties WindowProperties;
	};

	class Engine
	{
	public:
		Engine(const Engine&) = delete;
		Engine(Engine&&) = delete;
		Engine& operator=(const Engine&) = delete;
		Engine& operator=(Engine&&) = delete;
		virtual ~Engine();

		static Engine* Get();
		void Start();
		void Shutdown();
		EngineProperties& GetProperties();
		Window& GetWindow();

		virtual bool OnInit() = 0;
		virtual void OnDestroy() = 0;
		virtual void OnProcessInput() = 0;
		virtual void OnUpdate(DeltaTime dt) = 0;
		virtual void OnRender(DeltaTime dt) = 0;

	protected:
		Engine(const EngineProperties& engineProps);

	protected:
		EngineProperties m_Properties;

	private:
		static Engine* s_Instance;
		bool m_Initialized, m_Running;
		std::unique_ptr<Window> m_Window;
	};
}
