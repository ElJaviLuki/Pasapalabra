/*
	ball.h
	Author: F. Javier L. Cacenave - @ElJaviLuki

	For each of the balls contained by the Pasapalabra's donut.
*/

#pragma once

#include "donut_question.h"

#include <string>
#include <vector>

namespace DonutGame
{
	class Ball
	{
	public:
		enum class Result { Correct, Fail, Pending };

		//TODO: Ball(const Ball&);
		//TODO: Ball(Ball&&);
		Ball(const char letter,	const DonutQuestion&, const Result& = Result::Pending);
		//TODO: Moving converting constructor

		[[nodiscard]] std::string getDefinition() const noexcept;
		[[nodiscard]] std::vector<std::string> getAnswers() const noexcept;
		[[nodiscard]] Ball::Result getResult() const noexcept;
		[[nodiscard]] bool isCorrect() const noexcept;
		[[nodiscard]] bool isFail() const noexcept;
		[[nodiscard]] bool isPending() const noexcept;

		void setResult(const Ball::Result&) noexcept;
		//TODO: void setResult(Ball::Result&&) noexcept;
		void setCorrect() noexcept;
		void setFail() noexcept;
		void setPending() noexcept;

	private:
		char letter;
		DonutQuestion question;
		Result result;
	};
} // namespace DonutGame