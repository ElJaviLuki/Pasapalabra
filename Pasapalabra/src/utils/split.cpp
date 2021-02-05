/*
	split.cpp
	Author: F. Javier L. Cacenave - @ElJaviLuki
*/

#include "split.h"

namespace Utils
{
	std::vector<std::string> split(const std::string& origin, const std::string& delim)
	{
		std::vector<std::string> ret;
		auto originBegin = origin.begin();
		auto originEnd = origin.end();
		auto delimStart = delim.begin();
		auto delimEnd = delim.end();
		auto size = delim.length();

		do
		{
			auto find_itr = std::search(originBegin, originEnd, delimStart, delimEnd);
			auto sub = origin.substr(originBegin - origin.begin(), find_itr - originBegin);
			trim(sub);
			ret.emplace_back(sub);

			if (find_itr != originEnd)
			{
				originBegin = find_itr + size;
			}
			else return ret;
		} while (true);
	}
}
