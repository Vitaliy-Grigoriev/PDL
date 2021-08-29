project(PdlError   CXX)

# Build PDL Error library.
add_library(pdl_error   STATIC)
add_library(pdl::error   ALIAS   pdl_error)
set_target_properties(pdl_error   PROPERTIES   OUTPUT_NAME   error)

target_sources(pdl_error
    PRIVATE
        Error.cpp
        Utils.cpp
    PUBLIC
        Error.hpp
        Utils.hpp
)

install(
    TARGETS      pdl_error
    EXPORT       pdl
    DESTINATION  ${CMAKE_INSTALL_LIBDIR}
    COMPONENT    COMMON
)

install(
    FILES
        Error.hpp
        Utils.hpp
    DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/pdl/common/error
    COMPONENT    COMMON
)
