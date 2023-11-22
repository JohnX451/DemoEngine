#include <DemoEngine.h>

class Sandbox : public DemoEngine::Application {
public:
	Sandbox() {
		LOG_INFO("Sandbox constructor called");
	}

	~Sandbox() {
		LOG_INFO("Sandbox destructor called");
	}
};

DemoEngine::Application* DemoEngine::CreateApplication() {
	LOG_INFO("Creating sandbox application");
	return new Sandbox();
}