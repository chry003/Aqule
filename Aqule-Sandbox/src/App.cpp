#include "Aqule.hpp"

class Sandbox : public Aq::Application
{
public:
    Sandbox()
    {
        
    }
    ~Sandbox()
    {
        
    }
};

Aq::Application* Aq::CreateApplication()
{
    return new Sandbox();
}