#pragma once

#include "Statements.hpp"
#include "SkippedBlocks.hpp"
#include "../syntax/Syntax.hpp"


namespace pdl::spirit::grammar
{
    const auto skipper = skipped::whitespace | skipped::comment;


    const x3::rule<RuleId, syntax::ScriptEntry> scriptEntry{"Script Entry"};
    const x3::rule<RuleId, syntax::Script>      script{"Script"};


    const auto scriptEntry_def = statements::importStatement | statements::protocolStatement;
    const auto script_def = +scriptEntry;


    BOOST_SPIRIT_DEFINE(scriptEntry);
    BOOST_SPIRIT_DEFINE(script);

}  // namespace grammar.
