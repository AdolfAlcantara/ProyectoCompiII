cmake_minimum_required(VERSION 3.8)
project(sample1)

find_package(FLEX REQUIRED)

FLEX_TARGET(sample1 sample1.l  ${CMAKE_CURRENT_BINARY_DIR}/sample1_lexer.cpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${CMAKE_PROJECT_NAME} main.cpp ${FLEX_sample1_OUTPUTS})