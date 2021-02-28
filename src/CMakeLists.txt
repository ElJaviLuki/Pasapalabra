# Allow files inside these contained subdirectories to include header files using /src as a relative path.
include_directories(.)


add_subdirectory(web_service)
add_subdirectory(donut_game)
add_subdirectory(tests)
add_subdirectory(utils)
