add_library(pdl_common_meta   INTERFACE)
add_library(pdl::common::meta   ALIAS   pdl_common_meta)

target_include_directories(pdl_common_meta
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
