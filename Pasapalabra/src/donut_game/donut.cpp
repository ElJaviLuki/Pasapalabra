/*
	donut.cpp
	Author: F. Javier L. Cacenave - @ElJaviLuki
*/

#include "donut.h"

#include <iostream>

namespace DonutGame
{
	Donut::Donut(const DonutQuiz& quiz)
	{
		for (auto i = 0; i < quiz.size(); ++i)
		{
			balls.emplace_back(alphabet.at(i), quiz.at(i));
		}
	}

	size_t Donut::numBalls() const noexcept { return balls.size(); }

	Ball::Result Donut::getResult(const uint& numBall) const noexcept
	{
		return balls.at(numBall).getResult();
	}

	bool Donut::isCorrect(const uint& numBall) const noexcept
	{
		return balls.at(numBall).isCorrect();
	}

	bool Donut::isFail(const uint& numBall) const noexcept
	{
		return balls.at(numBall).isFail();
	}

	bool Donut::isPending(const uint& numBall) const noexcept
	{
		return balls.at(numBall).isPending();
	}

	void Donut::setResult(const uint& numBall, const Ball::Result& newResult)
	{
		auto& ball = balls.at(numBall);
		
		if (const auto& oldResult = ball.getResult();
			oldResult != newResult)
		{
			ball.setResult(newResult);

			switch (oldResult)
			{
				case Ball::Result::Correct: numCorrects--; break;
				case Ball::Result::Fail: numFails--; break;
				case Ball::Result::Pending: numPending--; break;
				default: break; //TODO: Unreachable code
			}

			switch (newResult)
			{
				case Ball::Result::Correct: numCorrects++; break;
				case Ball::Result::Fail: numFails++; break;
				case Ball::Result::Pending: numPending++; break;
				default: break; //TODO: Unreachable code
			}
		}
	}

	void Donut::setCorrect(const uint& numBall) noexcept { setResult(numBall, Ball::Result::Correct); }
	
	void Donut::setFail(const uint& numBall) noexcept { setResult(numBall, Ball::Result::Fail); }

	void Donut::setPending(const uint& numBall) noexcept { setResult(numBall, Ball::Result::Pending); }
} // namespace DonutGame