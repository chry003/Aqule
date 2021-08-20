#pragma once

#ifdef AQ_PLATFORM_LINUX
    #define Debug 1
#else
    #error Aquel only Support Linux!
#endif

#define BIT(x) (1 << x)