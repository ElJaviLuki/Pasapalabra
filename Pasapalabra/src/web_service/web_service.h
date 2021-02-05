/*
	web_service.h
	Author: F. Javier L. Cacenave - @ElJaviLuki

	Pasapalabra's web service
*/

#pragma once

#include "donut_game/donut_question.h"
#include "utils/split.h"
#include "utils/globals.h"

/* This needs to be defined to use HTTPS.
	TODO: Include SSL library. */
	//#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>
#include <rapidjson/document.h>

#include <vector>

namespace WebService
{
	[[nodiscard]] DonutGame::DonutQuiz getDonutQuiz(const uint& donutID);
}