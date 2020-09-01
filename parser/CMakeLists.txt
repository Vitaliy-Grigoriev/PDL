project(PdlParser   CXX)

# Select paths to include files of PDL library.
set(PDL_PARSER_INCLUDE_PATH   ${CMAKE_CURRENT_SOURCE_DIR}   PARENT_SCOPE)

# Build PDL Parser library.
add_library(pdl_parser   STATIC)
add_library(pdl::parser   ALIAS   pdl_parser)
set_target_properties(pdl_parser   PROPERTIES   OUTPUT_NAME   parser)

# Select source files of PDL syntax.
set(PDL_PARSER_SYNTAX
    spirit/syntax/Types.hpp
    spirit/syntax/Identifier.hpp
    spirit/syntax/Literals.hpp
    spirit/syntax/Properties.hpp
    spirit/syntax/Variables.hpp
    spirit/syntax/Methods.hpp
    spirit/syntax/Groups.hpp
    spirit/syntax/Statements.hpp
)

# Select source files of PDL grammar.
set(PDL_PARSER_GRAMMAR
    spirit/grammar/RuleId.hpp
    spirit/grammar/Types.hpp
    spirit/grammar/Keywords.hpp
    spirit/grammar/Identifier.hpp
    spirit/grammar/Symbols.hpp
    spirit/grammar/Literals.hpp
    spirit/grammar/Properties.hpp
    spirit/grammar/Variables.hpp
    spirit/grammar/Methods.hpp
    spirit/grammar/Groups.hpp
    spirit/grammar/Statements.hpp
    spirit/grammar/SkippedBlocks.hpp
    spirit/grammar/Actions.hpp
    spirit/grammar/Utils.hpp
)

# Select source files of PDL common.
set(PDL_PARSER_COMMON
    spirit/Annotation.hpp
    spirit/Handlers.hpp
    spirit/Syntax.hpp
    spirit/Grammar.hpp
)

target_sources(pdl_parser
    PRIVATE
        ${PDL_PARSER_SYNTAX}
        ${PDL_PARSER_GRAMMAR}
        ${PDL_PARSER_COMMON}
        Parser.cpp
    PUBLIC
        Parser.hpp
)

target_link_libraries(pdl_parser
    PRIVATE
        pdl::common
)

target_precompile_headers(pdl_parser
    PRIVATE
        spirit/BoostPrecompile.hpp
)

add_subdirectory(tests)
