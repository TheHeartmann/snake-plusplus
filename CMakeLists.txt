cmake_minimum_required(VERSION 3.2)
project(snake-plusplus)

set(CMAKE_CXX_STANDARD 14)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")



set(SOURCE_FILES Main.cpp SDL2_Standardproject/SDL/SDLPng.h SDL2_Standardproject/SDL/SDLPng.cpp)
add_executable(snake-plusplus_run ${SOURCE_FILES} SDL2_Standardproject/SDL/SDLPng.cpp)



include_directories(SDL2_Standardproject)
add_subdirectory(SDL2_Standardproject)
add_subdirectory(SnakePlusPlusTests)

target_link_libraries(snake-plusplus_run SDL2_Standardproject )
target_link_libraries(snake-plusplus_run ${SDL2_LIBRARY}; ${SDL2_IMAGE_LIBRARIES})