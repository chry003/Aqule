#include "Aqule.hpp"

class LayerTest : public Aq::Layer
{
public:
	LayerTest()
		: Layer("test")
	{

	}

	void OnUpdate() override
	{
		// AQ_INFO("Test Layer (update)");
	}

	void OnEvent(Aq::Event& event) override
	{
		// AQ_TRACE("{0}", event);
	}
};

class Sandbox : public Aq::Application
{
public:
    Sandbox()
    {
    	PushLayer(new LayerTest());
    }
    ~Sandbox()
    {
        
    }
};

Aq::Application* Aq::CreateApplication()
{
    return new Sandbox();
}