cmake_minimum_required(VERSION 3.28)
project(SFML-LEARNING LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

file(GLOB all_SRCS
        "${CMAKE_SOURCE_DIR}/include/*.hpp"
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        )

add_executable(main src/main.cpp src/grid.cpp src/gridspace.cpp include/grid.hpp include/draw.hpp src/draw.cpp include/shapes.hpp src/shapes.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)

