cmake_minimum_required(VERSION 3.6)
project(APTAssignment)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "-pedantic -Wall")

set(SOURCE_FILES player.h player.c helpers.c helpers.h game.c game.h carboard.c carboard.h board.c board.h)
add_executable(APTAssignment ${SOURCE_FILES})