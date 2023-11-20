#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "DemoEngine/Events/ApplicationEvent.h"

#include "Window.h"

namespace DemoEngine {

	class DEMOENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Defined in client
	Application* CreateApplication();

}