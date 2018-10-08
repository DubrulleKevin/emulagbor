#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.8)
project(emulagbor)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE RELEASE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_C_FLAGS "-std=c89 -pedantic -Wall -Wextra -Wno-unused-parameter ${CMAKE_C_FLAGS}")
endif()

include_directories("inc")

file(
        GLOB_RECURSE
        source_files
        src/*.c
)

# Define sources and executable
set(EXECUTABLE_NAME "emulagbor")
add_executable(${EXECUTABLE_NAME} ${source_files})
