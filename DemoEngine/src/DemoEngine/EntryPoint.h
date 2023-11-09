#pragma once

#ifdef DEMOENGINE_PLATFORM_WINDOWS

extern DemoEngine::Application* DemoEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("Demo Engine started...\n");
	auto app = DemoEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif