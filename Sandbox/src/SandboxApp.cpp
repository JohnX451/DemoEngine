#include <DemoEngine.h>

class Sandbox : public DemoEngine::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

DemoEngine::Application* DemoEngine::CreateApplication() {
	return new Sandbox();
}