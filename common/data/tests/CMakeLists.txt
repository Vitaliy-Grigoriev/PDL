if (DEFINED   PDL_WITH_TESTS)
    message("[info] PDL Data Tests Included.")

    pdl_test_create(raw_data)
    pdl_test_add_dependency(raw_data   pdl::data)

    pdl_test_add_source(raw_data   RawDataTest.cpp)

    pdl_test_register(raw_data)


    # Select source files of PDL Data tests.
    set(PDL_DATA_TEST_SOURCES
        test.cpp
        )

    # Build PDL tests.
    add_executable(data_test   ${PDL_DATA_TEST_SOURCES})
    target_link_libraries(data_test   pdl::data)

endif()
