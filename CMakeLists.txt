cmake_minimum_required(VERSION 3.2)
project(snake-plusplus)

set(CMAKE_CXX_STANDARD 14)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
    


set(SOURCE_FILES Main.cpp)
add_executable(snake-plusplus_run ${SOURCE_FILES} )



#INCLUDE(FindPkgConfig)
#PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
#PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
#PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer)

SET(SDL2_INCLUDE_DIR SDL2_Standardproject/SDL2)
SET(SDL2_IMAGE_INCLUDE_DIR SDL2_Standardproject/SDL2)
SET(SDL2_MIXER_INCLUDE_DIR SDL2_Standardproject/SDL2)
SET(SDL2_TTF_INCLUDE_DIR SDL2_Standardproject/SDL2)


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)



include_directories(SDL2_Standardproject)
add_subdirectory(SDL2_Standardproject)
add_subdirectory(SnakePlusPlusTests)

target_link_libraries(snake-plusplus_run SDL2_Standardproject)
target_link_libraries(snake-plusplus_run ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARY})