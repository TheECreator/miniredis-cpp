cmake_minimum_required(VERSION 3.25)

project(
    MiniRedis
    VERSION 0.1.0
    DESCRIPTION "A Redis-inspired in-memory key-value database written in modern C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(miniredis
    src/main.cpp
)

target_include_directories(miniredis
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(miniredis PRIVATE /W4 /permissive-)
else()
    target_compile_options(miniredis PRIVATE -Wall -Wextra -Wpedantic)
endif()