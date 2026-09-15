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

include(FetchContent)

# -------------------------
# Core library
# -------------------------

add_library(miniredis_core
    src/database.cpp
)

target_include_directories(miniredis_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(miniredis_core PRIVATE /W4 /permissive-)
else()
    target_compile_options(miniredis_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# -------------------------
# Main executable
# -------------------------

add_executable(miniredis
    src/main.cpp
)

target_link_libraries(miniredis
    PRIVATE
        miniredis_core
)

# -------------------------
# GoogleTest
# -------------------------

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(database_tests
    tests/database_tests.cpp
)

target_link_libraries(database_tests
    PRIVATE
        miniredis_core
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(database_tests)