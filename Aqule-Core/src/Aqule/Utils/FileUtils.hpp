#pragma once

#include "aqpcz.hpp"
#include "Aqule/Core/log.hpp"

namespace Aq {

	std::string ReadFile(const char* path)
	{
		std::string file;
		std::ifstream fileStream(path, std::ios::in);
		if(fileStream.is_open())
		{
			std::stringstream sstr;
			sstr << fileStream.rdbuf();
			file = sstr.str();
			fileStream.close();
		}
		else
		{
			AQ_CORE_ERROR("Failed to open File: {0}", path);
		}

		return file;
	}

}