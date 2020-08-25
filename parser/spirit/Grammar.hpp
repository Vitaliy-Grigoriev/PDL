#pragma once

#include "parser/spirit/grammar/SkippedBlocks.hpp"
#include "parser/spirit/grammar/Statements.hpp"

#include <parser/spirit/Syntax.hpp>


namespace pdl::spirit::grammar {

constexpr auto skipper = skipped::whitespace | skipped::comment;


constexpr x3::rule<RuleId, syntax::ScriptEntry>   scriptEntry   { "Script Entry" };
constexpr x3::rule<RuleId, syntax::Script>        script        { "Script" };


constexpr auto scriptEntry_def = statements::importStatement | statements::protocolStatement;
constexpr auto script_def      = +scriptEntry;


BOOST_SPIRIT_DEFINE(scriptEntry);
BOOST_SPIRIT_DEFINE(script);

}  // namespace grammar.
