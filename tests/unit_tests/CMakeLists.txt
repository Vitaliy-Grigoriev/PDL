project(PdlUnitTest   CXX)

macro(pdl_test_init)

    enable_testing()
    include(GoogleTest)

endmacro()

macro(pdl_test_create   _name)

    add_executable(${_name}_test)
    target_link_libraries(${_name}_test
        PRIVATE
            GTest::gtest
            GTest::gtest_main
    )

endmacro()

macro(pdl_test_add_dependency   _name   _lib)

    target_link_libraries(${_name}_test
        PRIVATE
            ${_lib}
    )

endmacro()

macro(pdl_test_add_source   _name)

    target_sources(${_name}_test
        PRIVATE
            ${ARGN}
    )

endmacro()

macro(pdl_test_register   _name)

    gtest_discover_tests(${_name}_test
        EXTRA_ARGS
            --gtest_shuffle
            --gtest_repeat=5
            --gtest_random_seed=0
            --gtest_output=xml:${PROJECT_BINARY_DIR}/reports/
    )

endmacro()
