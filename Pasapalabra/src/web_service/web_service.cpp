/*
	web_service.cpp
	Author: F. Javier L. Cacenave - @ElJaviLuki

	TODO:
	· Implement HTTPS support
	· Implement support for Spanish characters.
	· Connection error handling
*/

#pragma once

#include "web_service.h"

namespace WebService
{
	[[nodiscard]] inline httplib::Result downloadDonut(const uint& donutID)
	{

#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
		const char* host{ "https://atreslab.com" };
#else
		const char* host{ "http://atreslab.com" };
#endif

		return httplib::Client(host)
			.Get(("/modulosblancos/" + std::to_string(donutID) + "/").c_str());
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