#pragma once

#include "Variables.hpp"
#include "../syntax/Groups.hpp"


namespace pdl::spirit::grammar::groups
{
    struct GroupRuleId : RuleId {
    };

    const x3::rule<GroupRuleId, syntax::groups::GroupEntry>           groupEntry           {"Group Entry"};
    const x3::rule<GroupRuleId, syntax::groups::StaticGroup>          staticGroup          {"Static Group"};
    const x3::rule<GroupRuleId, syntax::groups::ConditionalGroup>     conditionalGroup     {"Conditional Group"};
    const x3::rule<GroupRuleId, syntax::groups::OptionalGroupEntry>   optionalGroupEntry   {"Optional Group Entry"};
    const x3::rule<GroupRuleId, syntax::groups::OptionalGroup>        optionalGroup        {"Optional Group"};


    const auto groupEntry_def         = keywords::groupKeyword > identifier > utils::makeBlockBrace(+variables::variable);
    const auto staticGroup_def        = utils::makeSquareBrace(keywords::staticKeyword) > +variables::variable;
    const auto conditionalGroup_def   = utils::makeSquareBrace(keywords::conditionalKeyword) > +variables::variable;
    const auto optionalGroupEntry_def = variables::variable | groupEntry;
    const auto optionalGroup_def      = utils::makeSquareBrace(keywords::optionalKeyword, keywords::optionalGroupType) > +optionalGroupEntry;


    BOOST_SPIRIT_DEFINE(groupEntry);
    BOOST_SPIRIT_DEFINE(staticGroup);
    BOOST_SPIRIT_DEFINE(conditionalGroup);
    BOOST_SPIRIT_DEFINE(optionalGroupEntry);
    BOOST_SPIRIT_DEFINE(optionalGroup);

}  // namespace groups.
