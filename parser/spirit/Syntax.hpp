#pragma once

#include "parser/spirit/syntax/Statements.hpp"

#include <core/Declaration.hpp>


namespace pdl::spirit::syntax {

struct ScriptEntry : x3::variant<statements::ImportStatement,
                                 statements::ProtocolStatement>,
                     Annotation<ScriptEntry>
{
    using base_type::base_type;
    using base_type::operator=;
};

struct Script : core::Declaration<Script>,
                Annotation<Script>
{
    Script() :
        Declaration{ this }
    { }

    std::vector<ScriptEntry> statements;
};

}  // namespace syntax.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::Script, statements)
