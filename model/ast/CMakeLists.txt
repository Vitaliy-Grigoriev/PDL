project(PdlAst   CXX)

# Build PDL Ast library.
add_library(pdl_ast   STATIC)
add_library(pdl::model::ast   ALIAS   pdl_ast)
set_target_properties(pdl_ast   PROPERTIES   OUTPUT_NAME   ast)

target_link_libraries(pdl_ast
    PRIVATE
        pdl::core
)

target_sources(pdl_ast
    PRIVATE
        AstTree.hpp   AstTree.cpp
)
