cmake_minimum_required(VERSION 3.17.3)
project(LeetCodeSolutions)

set(CMAKE_CXX_STANDARD 23)

add_executable(LeetCodeSolution 39/mainv1.cpp)

target_compile_options(LeetCodeSolution PRIVATE
        -Wall -Wextra -Wconversion -Wpedantic -O0 -g3)

set(CPM_DOWNLOAD_VERSION "v0.40.0")
include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/install_cpm_if_not_available.cmake)
unset(CPM_DOWNLOAD_VERSION)