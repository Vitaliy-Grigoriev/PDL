#pragma once

#include "Groups.hpp"
#include "../syntax/Statements.hpp"


namespace pdl::spirit::grammar::statements
{
    struct StatementRuleId : RuleId {
    };

    const x3::rule<StatementRuleId, syntax::statements::HeaderProperty>             headerProperty             {"Header Property"};
    const x3::rule<StatementRuleId, syntax::statements::ProtocolProperty>           protocolProperty           {"Protocol Property"};
    const x3::rule<StatementRuleId, syntax::statements::MappingEntryProperty>       mappingEntryProperty       {"Mapping Entry Property"};
    const x3::rule<StatementRuleId, syntax::statements::MappingStatementProperty>   mappingStatementProperty   {"Mapping Statement Property"};

    const x3::rule<StatementRuleId, syntax::statements::RoundStatement>         roundStatement         {"Round Statement"};
    const x3::rule<StatementRuleId, syntax::statements::RequestStatement>       requestStatement       {"Request Statement"};
    const x3::rule<StatementRuleId, syntax::statements::ResponseStatement>      responseStatement      {"Response Statement"};
    const x3::rule<StatementRuleId, syntax::statements::UsingStatement>         usingStatement         {"Using Statement"};
    const x3::rule<StatementRuleId, syntax::statements::StructStatement>        structStatement        {"Struct Statement"};
    const x3::rule<StatementRuleId, syntax::statements::HeaderEntry>            headerEntry            {"Header Entry"};
    const x3::rule<StatementRuleId, syntax::statements::HeaderStatement>        headerStatement        {"Header Statement"};
    const x3::rule<StatementRuleId, syntax::statements::MappingEntry>           mappingEntry           {"Mapping Entry"};
    const x3::rule<StatementRuleId, syntax::statements::MappingStatement>       mappingStatement       {"Mapping Statement"};
    const x3::rule<StatementRuleId, syntax::statements::DeclarationEntry>       declarationEntry       {"Declaration Entry"};
    const x3::rule<StatementRuleId, syntax::statements::StructureEntry>         structureEntry         {"Structure Entry"};
    const x3::rule<StatementRuleId, syntax::statements::DeclarationStatement>   declarationStatement   {"Declaration Statement"};
    const x3::rule<StatementRuleId, syntax::statements::StructureStatement>     structureStatement     {"Structure Statement"};
    const x3::rule<StatementRuleId, syntax::statements::ImportStatement>        importStatement        {"Import Statement"};
    const x3::rule<StatementRuleId, syntax::statements::ProtocolEntry>          protocolEntry          {"Protocol Entry"};
    const x3::rule<StatementRuleId, syntax::statements::ProtocolStatement>      protocolStatement      {"Protocol Statement"};


    const auto headerProperty_def           = properties::endianProperty |
                                              properties::ieeeProperty |
                                              properties::rfcProperty |
                                              properties::definitionProperty;
    const auto protocolProperty_def         = properties::rootProperty |
                                              properties::nextProtocolProperty;
    const auto mappingEntryProperty_def     = properties::defaultProperty |
                                              properties::idProperty |
                                              properties::definitionProperty;
    const auto mappingStatementProperty_def = properties::defaultProperty |
                                              properties::finalProperty |
                                              properties::idProperty |
                                              properties::definitionProperty |
                                              properties::endianProperty;

    const auto usingStatement_def       = keywords::usingKeyword > identifier > symbols::equality > variables::variableName;
    const auto structStatement_def      = keywords::structKeyword > identifier > -utils::makeCast(keywords::reservedTypes) > -utils::makeProperty(+headerProperty) > utils::makeBlockBrace(+variables::variable);
    const auto headerEntry_def          = groups::staticGroup | groups::conditionalGroup | groups::optionalGroup;
    const auto headerStatement_def      = keywords::headerKeyword > identifier > -utils::makeProperty(+headerProperty) > utils::makeBlockBrace(+headerEntry);
    const auto mappingEntry_def         = literals::literal >> -(symbols::property > +mappingEntryProperty);
    const auto mappingStatement_def     = keywords::mappingKeyword > variables::variableName > -(symbols::property > +mappingStatementProperty) > symbols::openBlockBrace > +mappingEntry > symbols::closeBlockBrace;
    const auto structureEntry_def       = usingStatement | structStatement | headerStatement | mappingStatement;
    const auto declarationEntry_def     = requestStatement | responseStatement;
    const auto structureStatement_def   = keywords::structureKeyword > symbols::openBlockBrace > +structureEntry > symbols::closeBlockBrace;
    const auto roundStatement_def       = keywords::roundKeyword > identifier > symbols::openBlockBrace > +variables::variable > symbols::closeBlockBrace;
    const auto requestStatement_def     = keywords::requestKeyword > symbols::openBlockBrace > +roundStatement > symbols::closeBlockBrace;
    const auto responseStatement_def    = keywords::responseKeyword > symbols::openBlockBrace > +roundStatement > symbols::closeBlockBrace;
    const auto declarationStatement_def = keywords::declarationKeyword > symbols::openBlockBrace > +declarationEntry > symbols::closeBlockBrace;
    const auto protocolEntry_def        = structureStatement | declarationStatement;
    const auto protocolStatement_def    = keywords::protocolKeyword > identifier > utils::makeProperty(+protocolProperty) > utils::makeBlockBrace(+protocolEntry);
    const auto importStatement_def      = keywords::importKeyword > identifier;


    BOOST_SPIRIT_DEFINE(headerProperty);
    BOOST_SPIRIT_DEFINE(protocolProperty);
    BOOST_SPIRIT_DEFINE(mappingEntryProperty);
    BOOST_SPIRIT_DEFINE(mappingStatementProperty);

    BOOST_SPIRIT_DEFINE(usingStatement);
    BOOST_SPIRIT_DEFINE(structStatement);
    BOOST_SPIRIT_DEFINE(headerEntry);
    BOOST_SPIRIT_DEFINE(headerStatement);
    BOOST_SPIRIT_DEFINE(mappingEntry);
    BOOST_SPIRIT_DEFINE(mappingStatement);
    BOOST_SPIRIT_DEFINE(structureEntry);
    BOOST_SPIRIT_DEFINE(roundStatement);
    BOOST_SPIRIT_DEFINE(requestStatement);
    BOOST_SPIRIT_DEFINE(responseStatement);
    BOOST_SPIRIT_DEFINE(declarationEntry);
    BOOST_SPIRIT_DEFINE(structureStatement);
    BOOST_SPIRIT_DEFINE(declarationStatement);
    BOOST_SPIRIT_DEFINE(protocolEntry);
    BOOST_SPIRIT_DEFINE(protocolStatement);
    BOOST_SPIRIT_DEFINE(importStatement);

}  // namespace statements.
