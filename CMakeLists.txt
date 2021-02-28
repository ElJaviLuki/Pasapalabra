
cmake_minimum_required (VERSION 3.8)

## Project settings
project (
	# Project Name
	"pspl"

	# Version
	# VERSION

	# Description
	DESCRIPTION "Pasapalabra Game"

	# Homepage URL
	HOMEPAGE_URL "https://github.com/ElJaviLuki/Pasapalabra"

	# Languages
	LANGUAGES CXX
)

## Set C++ Language Standard
# Set C++20 Standard
set(CMAKE_CXX_STANDARD 20)
# Require the use of that C++ standard.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Subdirectories (add according to dependency order)
add_subdirectory(externals)
add_subdirectory(src)