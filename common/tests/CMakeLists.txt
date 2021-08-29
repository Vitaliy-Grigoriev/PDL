if (DEFINED   PDL_WITH_TESTS)
    message("[info] PDL Common Tests Included.")

    # Select source files of PDL tests.
    set(PDL_COMMON_TEST_SOURCES
        test.cpp
        )

    # Build PDL tests.
    add_executable(common_test   ${PDL_COMMON_TEST_SOURCES})
    target_link_libraries(common_test   pdl::common)

endif()
