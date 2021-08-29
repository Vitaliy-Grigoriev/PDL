if (DEFINED   PDL_WITH_TESTS)
    message("[info] PDL Endian Tests Included.")

    pdl_test_create(endian)
    pdl_test_add_dependency(endian   pdl::core::data)
    pdl_test_add_dependency(endian   pdl::core::endian)

    pdl_test_add_source(endian   EndianTest.cpp)
    pdl_test_add_source(endian   BigEndianTest.cpp)
    pdl_test_add_source(endian   LittleEndianTest.cpp)

    pdl_test_register(endian)

endif()
