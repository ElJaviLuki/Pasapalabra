## Definitions for all external libraries

# cpp-httplib
	add_library(cpp-httplib INTERFACE)
	target_include_directories(cpp-httplib INTERFACE cpp-httplib)

# rapidjson
	add_library(rapidjson INTERFACE)
	target_include_directories(rapidjson INTERFACE rapidjson/include)