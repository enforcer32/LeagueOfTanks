#include "LOTEnginePCH.h
#include "LOTEngine/Core/Engine.h"
#include "LOTEngine/Core/Logger.h"
#include "LOTEngine/Core/DeltaTime.h"
#include "LOTEngine/Utils/DateTime.h"
#include "LOTEngine/Core/Assertion.h"

namespace LOT
{
	Engine* Engine::s_Instance = nullptr;

	Engine::Engine(const EngineProperties& engineProps)
	{
		LOT_ASSERT(!s_Instance, "ENGINE ALREADY INITIALIZED");
		s_Instance = this;
		m_Properties = engineProps;

		Logger::Init();

		m_Window = std::make_unique<Window>();
		if (!m_Window->Init(m_Properties.WindowProperties))
			LOT_LOG_CRITICAL("Failed to Initialize Window");
	}

	Engine::~Engine()
	{
		if (m_Initialized)
		{
			m_Window->Destroy();
		}
	}

	Engine* Engine::Get()
	{
		return s_Instance;
	}

	void Engine::Start()
	{
		if (!OnInit())
			LOT_LOG_CRITICAL("Engine OnInit Failed");

		m_Initialized = true;
		m_Running = true;

		DeltaTime lastDelteTime = 0.0;

		while (m_Running)
		{
			DeltaTime time = DateTime::GetTimeSeconds();
			DeltaTime dt = time - lastDelteTime;
			lastDelteTime = time;

			if (dt > 0)
			{
				OnProcessInput();
				OnUpdate(dt);
				OnRender(dt);
			}

			m_Window->Update();
		}

		OnDestroy();
	}

	void Engine::Shutdown()
	{
		m_Running = false;
	}

	EngineProperties& Engine::GetProperties()
	{
		return m_Properties;
	}

	Window& Engine::GetWindow()
	{
		return *m_Window;
	}
}
