/*
	donut.h
	Author: F. Javier L. Cacenave - @ElJaviLuki

	A Pasapalabra game's Donut.

	TODO:
	· Donut game remaining time
	· Copy and move constructors and operators
	· Iterator through donut balls

	NOTES:
	· 1. This constructor is not 'noexcept' since std::vector and std::string rely
	on dynamic allocation and can throw an exception.
*/

#pragma once

#include "ball.h"
#include "utils/globals.h"

#include <string_view>
#include <vector>

namespace DonutGame
{
	class Donut
	{
	public:
		//TODO Donut(const Donut&);
		//TODO Donut(Donut&&);
		explicit Donut(const DonutQuiz&); //Ind.1
		//TODO explicit Donut(const DonutQuiz&&);

		[[nodiscard]] size_t numBalls() const noexcept;

		[[nodiscard]] Ball::Result getResult(const uint& numBall) const noexcept;
		[[nodiscard]] bool isCorrect(const uint& numBall) const noexcept;
		[[nodiscard]] bool isFail(const uint& numBall) const noexcept;
		[[nodiscard]] bool isPending(const uint& numBall) const noexcept;

		void setResult(const uint& numBall, const Ball::Result& newResult);
		void setCorrect(const uint& numBall) noexcept;
		void setFail(const uint& numBall) noexcept;
		void setPending(const uint& numBall) noexcept;

	private:
		/*
			'alphabet'

			'constexpr': evaluated as a compile-time constant
			'static': for any instance of 'Donut'
			'std::string_view': since we can evaluate the size of 'std::string' at compile time and we can avoid std::string copies.
			· It's -so far- declared inside the 'Donut' scope, since we do not currently have plans to use it in other places, but this might change.
				Read: https://stackoverflow.com/questions/58918668/where-to-define-compile-time-constants
		*/
		constexpr static std::string_view alphabet{ "ABCDEFGHIJLMNÑOPQRSTUVXYZ" };

		std::vector<Ball> balls;
		uint numCorrects{ 0 };
		uint numFails{ 0 };
		uint numPending{ alphabet.size() };
	};
} // namespace DonutGame