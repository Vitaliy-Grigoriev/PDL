project(PdlCommon   CXX)

# Build PDL Common library.
add_library(pdl_common   STATIC)
add_library(pdl::common   ALIAS   pdl_common)
set_target_properties(pdl_common   PROPERTIES   OUTPUT_NAME   common)

target_sources(pdl_common
    PRIVATE
        Endian.cpp
        BinaryData.cpp
    PUBLIC
        Types.hpp
        Endian.hpp
        Memory.hpp
        BinaryData.hpp
        Declaration.hpp
)

add_subdirectory(tests)
