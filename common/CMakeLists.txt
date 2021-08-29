project(PdlCommon   CXX)

# Build PDL Common library.
add_library(pdl_common   STATIC)
add_library(pdl::common   ALIAS   pdl_common)
set_target_properties(pdl_common   PROPERTIES   OUTPUT_NAME   common)

include(meta.cmake)

add_subdirectory(error)
add_subdirectory(endian)
add_subdirectory(data)

target_sources(pdl_common
    PRIVATE
        Field.cpp
        Header.cpp
    PUBLIC
        Types.hpp
        Field.hpp
        Header.hpp
        Declaration.hpp
)

target_link_libraries(pdl_common
    PRIVATE
        pdl::common::meta
    PUBLIC
        pdl::data
        pdl::endian
        pdl::error
)

add_subdirectory(tests)
