project(SDL2_Standardproject)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR})

file(GLOB HEADER_FILES "*.h" "SDL/*.h" "*/*.h")
file(GLOB SOURCE_FILES "*.cpp" "SDL/*.cpp" "*/*.cpp")
file(GLOB IMAGE_FILES "Assets/gfx/*.bmp")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

add_library(SDL2_Standardproject STATIC ${SOURCE_FILES} ${HEADER_FILES} ${IMAGE_FILES})