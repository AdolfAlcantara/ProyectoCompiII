cmake_minimum_required (VERSION 3.0)
project (expr)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (LEXER_SRC "${PROJECT_SOURCE_DIR}/large_input.re")
set (PARSER_SRC "${PROJECT_SOURCE_DIR}/expr.y")

find_package(TREECC REQUIRED)

#Re2c
add_custom_command(
  OUTPUT expr_lexer.cpp
  COMMAND re2c -o expr_lexer.cpp ${LEXER_SRC}
  MAIN_DEPENDENCY ${LEXER_SRC}
)

#BISON
add_custom_command(
  OUTPUT expr_parser.h expr_parser.cpp
  COMMAND bison --defines=expr_parser.h -o expr_parser.cpp ${PARSER_SRC}
  MAIN_DEPENDENCY ${PARSER_SRC}
)

#TREECC
add_custom_command(
  OUTPUT expr_ast.cpp 
  COMMAND ${TREECC} -o expr_ast.cpp -h expr_ast.h ${PROJECT_SOURCE_DIR}/expr_ast.tc
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/expr_ast.tc
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME}  expr_ast.cpp
                                expr_lexer.cpp
                                expr_parser.cpp
                                main.cpp)