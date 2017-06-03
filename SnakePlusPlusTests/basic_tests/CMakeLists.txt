include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


file(GLOB_RECURSE SOURCE_FILES "*.cpp")

add_executable(runSnakePlusPlusTests ${SOURCE_FILES} ../../SDL2_Standardproject/SDL/SDLPng.h ../../SDL2_Standardproject/SDL/SDLPng.cpp)

target_link_libraries(runSnakePlusPlusTests gtest gtest_main)
target_link_libraries(runSnakePlusPlusTests SDL2_Standardproject)
