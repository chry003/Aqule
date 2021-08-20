#pragma once

#include "Core.hpp"

namespace Aq{
    class Application
    {
    public:
        Application();
        virtual ~Application();
    
        void Run();
    };
    
    Application* CreateApplication();
}