cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME SDL_GUI)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 26)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(/usr/local/Cellar/sdl2_mixer/2.8.0/include)
include_directories(/usr/local/Cellar/sdl2_mixer/2.8.0/lib)
include_directories(/usr/local/Cellar/sdl2_ttf/2.22.0/include)
include_directories(/usr/local/Cellar/sdl2_ttf/2.22.0/lib)

link_directories(/usr/local/Cellar/sdl2_mixer/2.8.0/include)
link_directories(/usr/local/Cellar/sdl2_mixer/2.8.0/lib)
link_directories(/usr/local/Cellar/sdl2_ttf/2.22.0/include)
link_directories(/usr/local/Cellar/sdl2_ttf/2.22.0/lib)

file(GLOB_RECURSE SOURCE "source/*.cpp")
file(GLOB_RECURSE HEADERS "headers/*.hpp")

include_directories(${SOURCE})
include_directories(${HEADERS})

add_executable(${PROJECT_NAME}
        ${SOURCE}
        ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_mixer SDL2_ttf)
