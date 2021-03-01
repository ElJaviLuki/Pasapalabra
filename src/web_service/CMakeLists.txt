add_library (
	web_service

	STATIC

	web_service.h web_service.cpp
)

target_link_libraries(
	web_service

	PUBLIC donut_game
	PUBLIC utils
	PUBLIC cpp-httplib
	PUBLIC rapidjson
)