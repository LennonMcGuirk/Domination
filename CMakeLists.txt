cmake_minimum_required(VERSION 3.15)
project(DominationProject C)

set(CMAKE_C_STANDARD 99)

add_executable(DominationProject main.c game_init.c game_init.h input_output.c input_output.h Definitions.h Libraries.h Game_Logic.c Game_Logic.h)