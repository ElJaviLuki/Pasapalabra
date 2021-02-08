/*
	trim.cpp
	Author: F. Javier L. Cacenave - @ElJaviLuki
	
	TODO:
	· Would we need to 'inline' these functions?
*/

#include "trim.h"

namespace Utils
{
	using StringIterator = std::_String_iterator<std::_String_val<std::_Simple_types<char>>>;

	[[nodiscard]] inline bool isSpace(const char& iterator) noexcept { return iterator == ' '; }

	StringIterator trimEnd(StringIterator inBegin, StringIterator inEnd)
	{
		for (auto iterator = inEnd; iterator != inBegin;)
		{
			if (!isSpace(*(--iterator)))
			{
				return ++iterator;
			}
		}

		return inBegin;
	}

	StringIterator trimBegin(StringIterator inBegin, StringIterator inEnd)
	{
		auto iterator = inBegin;

		while (iterator != inEnd && isSpace(*iterator))
		{
			++iterator;
		}

		return iterator;
	}

	void trimRight(std::string& input)
	{
		input.erase(
			trimEnd(
				std::begin(input),
				std::end(input)),
			std::end(input)
		);
	}

	void trimLeft(std::string& input)
	{
		input.erase(
			std::begin(input),
			trimBegin(
				std::begin(input),
				std::end(input)));
	}

	void trim(std::string& input)
	{
		trimRight(input);
		trimLeft(input);
	}
} // namespace Utils