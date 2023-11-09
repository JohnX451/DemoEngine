#pragma once

#ifdef DEMOENGINE_PLATFORM_WINDOWS

extern DemoEngine::Application* DemoEngine::CreateApplication();

int main(int argc, char** argv)
{
	DemoEngine::Log::Init();
	LOG_CORE_INFO("Logger initialized (engine core)");
	LOG_INFO("Logger initialized (client application)");

	auto app = DemoEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif