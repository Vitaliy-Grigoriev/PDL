project(PdlCore   CXX)

# Build PDL Core library.
add_library(pdl_core   STATIC)
add_library(pdl::core   ALIAS   pdl_core)
set_target_properties(pdl_core   PROPERTIES   OUTPUT_NAME   core)

include(meta.cmake)

add_subdirectory(error)
add_subdirectory(endian)
add_subdirectory(data)

target_sources(pdl_core
    PRIVATE
        Field.cpp
        Header.cpp
    PUBLIC
        Types.hpp
        Field.hpp
        Header.hpp
        Declaration.hpp
)

target_link_libraries(pdl_core
    PRIVATE
        pdl::core::meta
    PUBLIC
        pdl::core::data
        pdl::core::endian
        pdl::core::error
)

add_subdirectory(tests)
