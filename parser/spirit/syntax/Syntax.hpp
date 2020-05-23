#pragma once

#include "Statements.hpp"

#include <common/Declaration.hpp>


namespace pdl::spirit::syntax {

struct ScriptEntry : x3::variant<statements::ImportStatement,
                                 statements::ProtocolStatement>,
                     Annotation<ScriptEntry>
{
    ScriptEntry & operator= (const ScriptEntry &) = default;
    ScriptEntry (const ScriptEntry &) = default;
    ScriptEntry() = default;

    using base_type::base_type;
    using base_type::operator=;
};

struct Script : common::Declaration<Script>,
                Annotation<Script>
{
    std::vector<ScriptEntry> statements;
};

}  // namespace syntax.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::Script, statements)
