project(PdlData   CXX)

# Build PDL Data library.
add_library(pdl_data   STATIC)
add_library(pdl::core::data   ALIAS   pdl_data)
set_target_properties(pdl_data   PROPERTIES   OUTPUT_NAME   data)

target_sources(pdl_data
    PRIVATE
        RawData.cpp
    PUBLIC
        Memory.hpp
        PredefinedBytes.hpp
        RawData.hpp
)

target_link_libraries(pdl_data
    PRIVATE
        pdl::core::meta
    PUBLIC
        pdl::core::error
)

add_subdirectory(tests)

install(
   TARGETS      pdl_data
   EXPORT       pdl
   DESTINATION  ${CMAKE_INSTALL_LIBDIR}
   COMPONENT    CORE
)

install(
   FILES
       Memory.hpp
       PredefinedBytes.hpp
       RawData.hpp
   DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/pdl/core/data
   COMPONENT    CORE
)
