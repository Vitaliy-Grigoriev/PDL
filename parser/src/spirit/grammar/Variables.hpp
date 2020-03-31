#pragma once

#include "Properties.hpp"
#include "../syntax/Variables.hpp"


namespace pdl::spirit::grammar::variables
{
    struct VariableRuleId : RuleId {
    };

    const x3::rule<VariableRuleId, syntax::variables::Identifier>            identifier            {"Identifier"};
    const x3::rule<VariableRuleId, syntax::variables::VariableType>          variableType          {"Variable Type"};
    const x3::rule<VariableRuleId, syntax::variables::MemberVariable>        memberVariable        {"Member Variable"};
    const x3::rule<VariableRuleId, syntax::variables::VariableName>          variableName          {"Variable Name"};
    const x3::rule<VariableRuleId, syntax::variables::VariableProperty>      variableProperty      {"Variable Property"};
    const x3::rule<VariableRuleId, syntax::variables::VariableDeclaration>   variableDeclaration   {"Variable Declaration"};


    const auto identifier_def          = x3::raw[x3::lexeme[(x3::alnum) >> *(x3::alnum | symbols::underline)] - keywords::reservedWords];
    const auto variableType_def        = keywords::reservedTypes | identifier;
    const auto memberVariable_def      = identifier >> +(symbols::dot > identifier);
    const auto variableName_def        = memberVariable | identifier;
    const auto variableProperty_def    = properties::definitionProperty |
                                         properties::requiredProperty |
                                         properties::volatileProperty |
                                         properties::constProperty;
    const auto variableDeclaration_def = -keywords::variableScope >> variableType > identifier > -(symbols::equality >> literals::literal) > -(symbols::property >> +variableProperty);


    BOOST_SPIRIT_DEFINE(identifier);
    BOOST_SPIRIT_DEFINE(variableType);
    BOOST_SPIRIT_DEFINE(memberVariable);
    BOOST_SPIRIT_DEFINE(variableName);
    BOOST_SPIRIT_DEFINE(variableProperty);
    BOOST_SPIRIT_DEFINE(variableDeclaration);

}  // namespace variables.

