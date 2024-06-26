cmake_minimum_required(VERSION 3.29)

project(prime-headers)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_STANDARD_REQUIRED ON)

#deliberately not including these subdirectories by regex as precaution

include_directories(include/algorithms/sort)
include_directories(include/data_structures/vector)


enable_testing()
include(CTest)

add_subdirectory(tests/data_structures/vector)
