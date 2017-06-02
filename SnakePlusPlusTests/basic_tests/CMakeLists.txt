include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runSnakePlusPlusTests basic_check.cpp basic_check.cpp Point2D_tests.cpp Node_tests.cpp GameBoard_tests.cpp Snake_tests.cpp)

target_link_libraries(runSnakePlusPlusTests gtest gtest_main)
target_link_libraries(runSnakePlusPlusTests SDL2_Standardproject)
