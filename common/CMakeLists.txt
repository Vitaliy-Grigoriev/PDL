project(PdlCommon   CXX)

# Build PDL Common library.
add_library(pdl_common   STATIC)
add_library(pdl::common   ALIAS   pdl_common)
set_target_properties(pdl_common   PROPERTIES   OUTPUT_NAME   common)

target_sources(pdl_common
    PRIVATE
        Error.cpp
        Utils.cpp
        Endian.cpp
        RawData.cpp
        Field.cpp
        Header.cpp
    PUBLIC
        Error.hpp
        Utils.hpp
        Types.hpp
        Endian.hpp
        Memory.hpp
        RawData.hpp
        Field.hpp
        Header.hpp
        Declaration.hpp
)

add_subdirectory(tests)
