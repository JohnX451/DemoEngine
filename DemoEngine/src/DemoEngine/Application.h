#pragma once
#include "Core.h"

namespace DemoEngine {

	class DEMOENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Defined in client
	Application* CreateApplication();

}