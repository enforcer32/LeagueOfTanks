#include "LOTGamePCH.h"

#include <LOTEngine/Core/Engine.h>
#include <LOTEngine/Core/Logger.h>

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
			return true;
		}

		virtual void OnDestroy() override
		{

		}

		virtual void OnProcessInput() override
		{
		}

		virtual void OnUpdate(DeltaTime dt) override
		{
		}

		virtual void OnRender(DeltaTime dt) override
		{
		}

	private:
		// Scene Ref Here?
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
