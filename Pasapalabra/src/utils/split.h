/*
	split.h
	Author: F. Javier L. Cacenave - @ElJaviLuki

	TODO:
	· Can we change 'const std::string&' to 'std::string_view'? Has it benefits?
*/

#pragma once

#include "trim.h"

#include <algorithm>
#include <vector>

namespace Utils
{
	std::vector<std::string> split(const std::string& origin, const std::string& delim);
}