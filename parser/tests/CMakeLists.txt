include_directories(${PDL_PARSER_INCLUDE_PATH})

# Select source files of PDL tests.
set(PDL_TEST_SOURCES
    test.cpp
)

# Build PDL tests.
add_executable(_test   ${PDL_TEST_SOURCES})
target_link_libraries(_test   pdl::parser)
