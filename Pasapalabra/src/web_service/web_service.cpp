/*
	web_service.cpp
	Author: F. Javier L. Cacenave - @ElJaviLuki

	TODO:
	· Implement HTTPS support
	· Implement support for Spanish characters.
	· Connection error handling
	· Can donutID uint converted to std::string at compile time?
*/

#pragma once

#include "web_service.h"

namespace WebService
{
	/* Why is this function not inlined? */
	[[nodiscard]] inline httplib::Result downloadDonut(const uint& donutID)
	{
		return httplib::Client(
			/* Host */
			#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
						"https://atreslab.com"
			#else
						"http://atreslab.com"
			#endif
		).Get(("/modulosblancos/" + std::to_string(donutID) + "/").c_str());
	}

	DonutGame::DonutQuiz getDonutQuiz(const uint& donutID)
	{
		rapidjson::Document donutDocument;
		donutDocument.Parse(downloadDonut(donutID)->body.c_str());

		DonutGame::DonutQuiz donutJson;
		for (const auto& arrayElem : donutDocument.GetArray())
		{
			const auto& definition = arrayElem["pregunta"].GetString();
			const auto& answers = Utils::split(arrayElem["respuesta"].GetString(), ",");

			donutJson.push_back({ definition, answers });
		}

		return donutJson;
	}
} // namespace WebService