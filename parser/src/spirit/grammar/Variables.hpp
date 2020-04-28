#pragma once

#include "Properties.hpp"
#include "../syntax/Variables.hpp"


namespace pdl::spirit::grammar::variables
{
    struct VariableRuleId : RuleId {
    };

    const x3::rule<VariableRuleId, syntax::variables::VariableType>       variableType       {"Variable Type"};
    const x3::rule<VariableRuleId, syntax::variables::MemberVariable>     memberVariable     {"Member Variable"};
    const x3::rule<VariableRuleId, syntax::variables::VariableName>       variableName       {"Variable Name"};
    const x3::rule<VariableRuleId, syntax::variables::VariableProperty>   variableProperty   {"Variable Property"};

    const x3::rule<VariableRuleId, syntax::variables::VariableDeclaration>   variableDeclaration   {"Variable Declaration"};

    const x3::rule<VariableRuleId, syntax::variables::VariableListInit>                variableListInit                {"Variable List Init"};
    const x3::rule<VariableRuleId, syntax::variables::DesignatedInitializationValue>   designatedInitializationValue   {"Designated Initialization Value"};
    const x3::rule<VariableRuleId, syntax::variables::DesignatedInitialization>        designatedInitialization        {"Designated Initialization"};
    const x3::rule<VariableRuleId, syntax::variables::VariableDesignatedInit>          variableDesignatedInit          {"Variable Designated Init"};
    const x3::rule<VariableRuleId, syntax::variables::AggregateInitialization>         aggregateInitialization         {"Aggregate Initialization"};
    const x3::rule<VariableRuleId, syntax::variables::VariableInitialization>          variableInitialization          {"Variable Initialization"};

    const x3::rule<VariableRuleId, syntax::variables::Variable>   variable   {"Variable"};

    const auto variableType_def     = keywords::reservedTypes | identifier;
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

