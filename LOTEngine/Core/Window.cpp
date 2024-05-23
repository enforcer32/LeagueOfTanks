#include "LOTEnginePCH.h
#include "LOTEngine/Core/Window.h"
#include "LOTEngine/Core/Logger.h"

namespace LOT
{
	Window::Window()
		: m_Initialized(false), m_NativeWindow(nullptr)
	{
	}

	bool Window::Init(const WindowProperties& props)
	{
		m_WinPrivData.Name = props.Name;
		m_WinPrivData.Width = props.Width;
		m_WinPrivData.Height = props.Height;
		m_WinPrivData.VSync = props.VSync;
		if (!InitContext()) return false;
		return m_Initialized = true;
	}

	void Window::Destroy()
	{
		if (m_Initialized)
		{
			m_Initialized = false;
		}
	}

	void Window::Update()
	{
		//PollEvents & SwapBuffer
	}

	const WindowProperties& Window::GetProperties() const
	{
		return (WindowProperties&)m_WinPrivData;
	}

	void Window::SetProperties(const WindowProperties& props)
	{
		m_WinPrivData.Name = props.Name;
		m_WinPrivData.Width = props.Width;
		m_WinPrivData.Height = props.Height;
		m_WinPrivData.VSync = props.VSync;
	}

	bool Window::IsVSync() const
	{
		return m_WinPrivData.VSync;
	}

	void Window::SetVSync(bool vsync)
	{
		m_WinPrivData.VSync = vsync;
	}

	uint32_t Window::GetWidth() const
	{
		return m_WinPrivData.Width;
	}

	uint32_t Window::GetHeight() const
	{
		return m_WinPrivData.Height;
	}
	bool Window::InitContext()
	{
		// Init Window
		LOT_LOG_DEBUG("Initialized Window Context");
		return true;
	}
}
