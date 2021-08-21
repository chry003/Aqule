#pragma once

#ifdef AQ_PLATFORM_LINUX
    #ifdef AQ_DEBUG
		#define AQ_DEBUG_ENABLED true
	#else
		#define AQ_DEBUG_ENABLED false
	#endif
#else
    #error Aquel only Support Linux!
#endif