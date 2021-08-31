#pragma once

#include "Aqule/Core/log.hpp"

#ifdef AQ_PLATFORM_LINUX
    #ifdef AQ_DEBUG
		#define AQ_DEBUG_ENABLED true
	#else
		#define AQ_DEBUG_ENABLED false
	#endif
#else
    #error Aquel only Support Linux!
#endif

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#define __EXIT { exit(-1); }
#define ERR(err, ...) { if(!(err)) { AQ_CORE_ERROR("Error: {0}", __VA_ARGS__); __EXIT } }