cmake_minimum_required(VERSION 3.17)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)

add_executable(get_next_line test.c get_next_line_old.c get_next_line_utils_old.c get_next_line_old.h get_next_line.c get_next_line.h)