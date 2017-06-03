project(SDL2_Standardproject)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR})

file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE SOURCE_FILES "*.cpp")
file(GLOB IMAGE_FILES "Assets/gfx/*.bmp" "Assets/gfx/*.png")
file(GLOB MIXER_FILES "Assets/sfx/*.wav")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

add_library(SDL2_Standardproject STATIC ${SOURCE_FILES} ${HEADER_FILES} ${IMAGE_FILES} ${MIXER_FILES})