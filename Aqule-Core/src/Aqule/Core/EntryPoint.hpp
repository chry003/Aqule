#pragma once

#ifdef AQ_PLATFORM_LINUX

extern Aq::Application* Aq::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Aq::CreateApplication();
    app->Run();
    delete app;
}

#else
    #error Aquel only Support Linux!
#endif