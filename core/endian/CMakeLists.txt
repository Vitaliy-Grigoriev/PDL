project(PdlEndian   CXX)

# Build PDL Endian library.
add_library(pdl_endian   STATIC)
add_library(pdl::core::endian   ALIAS   pdl_endian)
set_target_properties(pdl_endian   PROPERTIES   OUTPUT_NAME   endian)

target_sources(pdl_endian
    PRIVATE
        Converter.cpp
        EngineInterface.cpp
        Engines.cpp
        Utils.cpp
        engines/impl/Common.cpp
        engines/impl/BigEndianImpl.cpp
        engines/impl/LittleEndianImpl.cpp
        engines/BigEndianEngine.cpp
        engines/LittleEndianEngine.cpp
    PUBLIC
        Converter.hpp
        Endian.hpp
        EngineInterface.hpp
        Engines.hpp
        Utils.hpp
        engines/impl/Common.hpp
        engines/impl/BigEndianImpl.hpp
        engines/impl/LittleEndianImpl.hpp
        engines/BigEndianEngine.hpp
        engines/LittleEndianEngine.hpp
)

target_link_libraries(pdl_endian
    PRIVATE
        pdl::core::meta
        pdl::core::data
    PUBLIC
        pdl::core::error
)

add_subdirectory(tests)

install(
   TARGETS      pdl_endian
   EXPORT       pdl
   DESTINATION  ${CMAKE_INSTALL_LIBDIR}
   COMPONENT    CORE
)

install(
   FILES
       Converter.hpp
       Endian.hpp
       EngineInterface.hpp
       Engines.hpp
       Utils.hpp
   DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/pdl/core/endian
   COMPONENT    CORE
)

install(
   FILES
        engines/impl/Common.hpp
        engines/impl/BigEndianImpl.hpp
        engines/impl/LittleEndianImpl.hpp
   DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/pdl/core/endian/engines/impl
   COMPONENT    CORE
)

install(
   FILES
       engines/BigEndianEngine.hpp
       engines/LittleEndianEngine.hpp
   DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/pdl/core/endian/engines
   COMPONENT    CORE
)
