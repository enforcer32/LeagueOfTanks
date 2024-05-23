#include "LOTGamePCH.h"

#include <LOTEngine/Core/Engine.h>
#include <LOTEngine/Core/Logger.h>
#include <LOTEngine/Scene/Scene.h>
#include <LOTEngine/Input/InputManager.h>

#include <imgui.h>

namespace LOT
{
	class LOTGame : public Engine
	{
	public:
		LOTGame(const EngineProperties& engineProps)
			: Engine(engineProps)
		{
		}

		virtual bool OnInit() override
		{
			LOT_LOG_INFO("Initializing League Of Tanks");
			m_ActiveScene = std::make_shared<Scene>("LOTGame");
			return true;
		}

		virtual void OnDestroy() override
		{

		}

		virtual void OnProcessInput() override
		{
			if (InputManager::IsKeyPressed(KeyCode::Escape))
				Shutdown();
		}

		virtual void OnUpdate(DeltaTime dt) override
		{
			m_ActiveScene->OnRuntimeUpdate(dt, m_EventManager);
		}

		virtual void OnRender(DeltaTime dt, const std::shared_ptr<Renderer2D>& renderer) override
		{
			renderer->ResetRenderStats();
			renderer->SetClearColor({ 0.2f, 0.3f, 0.3f, 1.0f });
			renderer->Clear();

			m_ActiveScene->OnRuntimeRender(dt, renderer);
		}

		virtual void OnImGuiRender(DeltaTime dt) override
		{
			/*auto& stats = m_Renderer2D->GetRenderStats();
			ImGui::Begin("Stats");
			ImGui::Text("Renderer2D Stats:");
			ImGui::Text("DrawCalls: %d", stats.DrawCallCount);
			ImGui::Text("QuadCount: %d", stats.QuadCount);
			ImGui::Text("VertexCount: %d", stats.GetVertexCount());
			ImGui::Text("IndexCount: %d", stats.GetIndexCount());
			ImGui::NewLine();
			ImGui::Text("Scene Stats:");
			ImGui::Text("Active Scene: %s", m_ActiveScene->GetName().c_str());
			ImGui::Text("FPS: %.2f", (1.0f / dt));
			ImGui::End();*/
		}

		virtual void OnWindowResize(WindowResizeEvent& ev) override
		{
			Engine::OnWindowResize(ev);
			m_ActiveScene->OnViewportResize(ev.GetWidth(), ev.GetHeight());
		}

	private:
		std::shared_ptr<Scene> m_ActiveScene;
	};
}

int main(int argc, char* argv)
{
	LOT::EngineProperties engineProps;
	engineProps.WindowProperties = { "League Of Tanks", 640, 480, true };
	LOT::LOTGame sandbox(engineProps);
	sandbox.Start();
	return 0;
}
