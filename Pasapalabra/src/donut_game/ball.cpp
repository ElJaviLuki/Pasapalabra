/*
	ball.cpp
	Author: F. Javier L. Cacenave - @ElJaviLuki
*/

#include "ball.h"

namespace DonutGame
{
	Ball::Ball(const char letter, const DonutQuestion& question, const Result& result) :
		letter{ letter }, question{ question }, result{ result } {};

	std::string Ball::getDefinition() const noexcept { return question.definition; }

	std::vector<std::string> Ball::getAnswers() const noexcept { return question.answers; }

	Ball::Result Ball::getResult() const noexcept { return result; }

	bool Ball::isCorrect() const noexcept { return result == Result::Correct; }

	bool Ball::isFail() const noexcept { return result == Result::Fail; }

	bool Ball::isPending() const noexcept { return result == Result::Pending; }

	void Ball::setResult(const Ball::Result& newResult) noexcept { result = newResult; }

	void Ball::setCorrect() noexcept { result = Result::Correct; }

	void Ball::setFail() noexcept {	result = Result::Fail; }

	void Ball::setPending() noexcept { result = Result::Pending; }
}