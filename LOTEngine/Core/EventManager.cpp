#include "LOTEnginePCH.h
#include "LOTEngine/Core/EventManager.h"

namespace LOT
{
	bool EventManager::Init()
	{
		return m_Initialized = true;
	}

	void EventManager::Destroy()
	{
		m_Initialized = false;
	}
}
