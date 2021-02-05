/*
	donut_question.h
	Author: F. Javier L. Cacenave - @ElJaviLuki
*/

#pragma once

#include <string>
#include <vector>

namespace DonutGame
{
	struct DonutQuestion
	{
		std::string definition;
		std::vector<std::string> answers;
	};

	using DonutQuiz = std::vector<DonutQuestion>;
}