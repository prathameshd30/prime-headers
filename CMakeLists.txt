cmake_minimum_required(VERSION 3.28) # Needed to reduce version for compatibility with MS VS 2022

project(prime-headers)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
##set(CMAKE_BUILD_TYPE Release)

# deliberately not including these subdirectories by glob regex as precaution

include_directories(include/algorithms/sort)
include_directories(include/data_structures/vector)


enable_testing()
include(CTest)

add_subdirectory(tests/data_structures/vector)
