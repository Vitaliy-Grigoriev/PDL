if (DEFINED   PDL_WITH_TESTS)
    message("[info] PDL Core Tests Included.")

    # Select source files of PDL tests.
    set(PDL_CORE_TEST_SOURCES
        test.cpp
    )

    # Build PDL tests.
    add_executable(core_test   ${PDL_CORE_TEST_SOURCES})
    target_link_libraries(core_test   pdl::core)

endif()
