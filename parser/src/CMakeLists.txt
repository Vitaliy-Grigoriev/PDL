cmake_minimum_required(VERSION   3.10)

# Select paths to include files of PDL library.
set(PDL_PARSER_INCLUDE_PATH   ${CMAKE_CURRENT_SOURCE_DIR}   PARENT_SCOPE)

# Select source files of PDL library.
set(PDL_PARSER_SOURCES
    Parser.cpp
)

include_directories(${CMAKE_SYSTEM_INCLUDE_PATH}/boost)

# Build PDL library.
add_library(pdl   STATIC   ${PDL_PARSER_SOURCES})
target_link_libraries(pdl   stdc++fs)
