add_library(pdl_core_meta   INTERFACE)
add_library(pdl::core::meta   ALIAS   pdl_core_meta)

target_include_directories(pdl_core_meta
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
