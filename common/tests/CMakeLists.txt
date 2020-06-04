pdl_test_create(binary_data)
pdl_test_add_dependency(binary_data   pdl::common)

pdl_test_add_source(binary_data   EndianTest.cpp)
pdl_test_add_source(binary_data   BinaryDataTest.cpp)

pdl_test_register(binary_data)