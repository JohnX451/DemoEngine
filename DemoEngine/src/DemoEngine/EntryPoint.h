#pragma once

#ifdef DEMOENGINE_PLATFORM_WINDOWS

extern DemoEngine::Application* DemoEngine::CreateApplication();

int main(int argc, char** argv)
{
	DemoEngine::Log::Init();
	LOG_CORE_INFO("Logger (engine core) initialized in entry point");
	LOG_INFO("Logger (client application) initialized in entry point");

	auto app = DemoEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif