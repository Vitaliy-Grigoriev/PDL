#pragma once

#include "Properties.hpp"

#include <parser/spirit/syntax/Variables.hpp>


namespace pdl::spirit::grammar::variables {

struct VariableRuleId : RuleId {
};

constexpr x3::rule<VariableRuleId, syntax::variables::ArrayType>          arrayType          { "Array Type" };
constexpr x3::rule<VariableRuleId, syntax::variables::ArrayVariable>      arrayVariable      { "Array Variable" };
constexpr x3::rule<VariableRuleId, syntax::variables::VariableType>       variableType       { "Variable Type" };
constexpr x3::rule<VariableRuleId, syntax::variables::MemberVariable>     memberVariable     { "Member Variable" };
constexpr x3::rule<VariableRuleId, syntax::variables::VariableName>       variableName       { "Variable Name" };
constexpr x3::rule<VariableRuleId, syntax::variables::VariableProperty>   variableProperty   { "Variable Property" };

constexpr x3::rule<VariableRuleId, syntax::variables::VariableDeclaration>   variableDeclaration   { "Variable Declaration" };

constexpr x3::rule<VariableRuleId, syntax::variables::VariableListInit>                variableListInit                { "Variable List Init" };
constexpr x3::rule<VariableRuleId, syntax::variables::DesignatedInitializationValue>   designatedInitializationValue   { "Designated Initialization Value" };
constexpr x3::rule<VariableRuleId, syntax::variables::DesignatedInitialization>        designatedInitialization        { "Designated Initialization" };
constexpr x3::rule<VariableRuleId, syntax::variables::VariableDesignatedInit>          variableDesignatedInit          { "Variable Designated Init" };
constexpr x3::rule<VariableRuleId, syntax::variables::AggregateInitialization>         aggregateInitialization         { "Aggregate Initialization" };
constexpr x3::rule<VariableRuleId, syntax::variables::VariableInitialization>          variableInitialization          { "Variable Initialization" };

constexpr x3::rule<VariableRuleId, syntax::variables::Variable>   variable   { "Variable" };


const auto arrayType_def        = keywords::reservedTypes | identifier;
const auto arrayVariable_def    = arrayType >> utils::makeSquareBraceExpect(x3::uint16);
const auto variableType_def     = arrayVariable | keywords::reservedTypes | identifier;
const auto memberVariable_def   = identifier >> +(symbols::dot > identifier);
const auto variableName_def     = memberVariable | identifier;
const auto variableProperty_def = properties::definitionProperty |
                                  properties::requiredProperty |
                                  properties::endianProperty |
                                  properties::priorityProperty |
                                  properties::ieeeProperty |
                                  properties::rfcProperty |
                                  properties::variableProperty |
                                  properties::constProperty |
                                  properties::calculatedProperty;

const auto variableDeclaration_def = -keywords::variableScope >> variableType > identifier;

const auto variableListInit_def              = literals::literal % symbols::comma;
const auto designatedInitializationValue_def = literals::literal | aggregateInitialization;
const auto designatedInitialization_def      = literals::designatorLiteral > symbols::equality > designatedInitializationValue;
const auto variableDesignatedInit_def        = designatedInitialization % symbols::comma;
const auto aggregateInitialization_def       = symbols::openBlockBrace > (variableDesignatedInit | variableListInit) > symbols::closeBlockBrace;
const auto variableInitialization_def        = literals::literal | aggregateInitialization;

const auto variable_def = variableDeclaration > -(symbols::equality > variableInitialization) > -(symbols::property > +variableProperty);


BOOST_SPIRIT_DEFINE(arrayType);
BOOST_SPIRIT_DEFINE(arrayVariable);
BOOST_SPIRIT_DEFINE(variableType);
BOOST_SPIRIT_DEFINE(memberVariable);
BOOST_SPIRIT_DEFINE(variableName);
BOOST_SPIRIT_DEFINE(variableProperty);

BOOST_SPIRIT_DEFINE(variableDeclaration);

BOOST_SPIRIT_DEFINE(variableListInit);
BOOST_SPIRIT_DEFINE(designatedInitializationValue);
BOOST_SPIRIT_DEFINE(designatedInitialization);
BOOST_SPIRIT_DEFINE(variableDesignatedInit);
BOOST_SPIRIT_DEFINE(aggregateInitialization);
BOOST_SPIRIT_DEFINE(variableInitialization);

BOOST_SPIRIT_DEFINE(variable);

}  // namespace variables.
