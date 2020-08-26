pdl_test_create(raw_data)
pdl_test_add_dependency(raw_data   pdl::common)

pdl_test_add_source(raw_data   EndianTest.cpp)
pdl_test_add_source(raw_data   RawDataTest.cpp)

pdl_test_register(raw_data)


# Select source files of PDL tests.
set(PDL_COMMON_TEST_SOURCES
    test.cpp
    )

# Build PDL tests.
add_executable(common_test   ${PDL_COMMON_TEST_SOURCES})
target_link_libraries(common_test   pdl::common)
