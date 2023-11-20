#include "pch.h"
#include "Application.h"

#include "DemoEngine/Events/ApplicationEvent.h"
#include "DemoEngine/Log.h"

namespace DemoEngine {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		LOG_CORE_TRACE(e);

		while (true)
		{
			
		}
	}

}
