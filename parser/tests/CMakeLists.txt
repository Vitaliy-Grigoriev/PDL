cmake_minimum_required(VERSION   3.10)

# Select source files of PDL tests.
set(PDL_TEST_SOURCES
    test.cpp
)

# Build PDL tests.
add_executable(test   ${PDL_TEST_SOURCES})
target_link_libraries(test   pdl)
