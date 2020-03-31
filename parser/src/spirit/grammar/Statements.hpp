#pragma once

#include "Variables.hpp"
#include "../syntax/Statements.hpp"


namespace pdl::spirit::grammar::statements
{
    struct StatementRuleId : RuleId {
    };

    const x3::rule<StatementRuleId, syntax::statements::MappingEntryProperty>       mappingEntryProperty       {"Mapping Entry Property"};
    const x3::rule<StatementRuleId, syntax::statements::MappingStatementProperty>   mappingStatementProperty   {"Mapping Statement Property"};

    const x3::rule<StatementRuleId, syntax::statements::RoundStatement>         roundStatement         {"Round Statement"};
    const x3::rule<StatementRuleId, syntax::statements::RequestStatement>       requestStatement       {"Request Statement"};
    const x3::rule<StatementRuleId, syntax::statements::ResponseStatement>      responseStatement      {"Response Statement"};
    const x3::rule<StatementRuleId, syntax::statements::UsingStatement>         usingStatement         {"Using Statement"};
    const x3::rule<StatementRuleId, syntax::statements::HeaderStatement>        headerStatement        {"Header Statement"};
    const x3::rule<StatementRuleId, syntax::statements::MappingEntry>           mappingEntry           {"Mapping Entry"};
    const x3::rule<StatementRuleId, syntax::statements::MappingStatement>       mappingStatement       {"Mapping Statement"};
    const x3::rule<StatementRuleId, syntax::statements::DeclarationEntry>       declarationEntry       {"Declaration Entry"};
    const x3::rule<StatementRuleId, syntax::statements::DefinesEntry>           definesEntry           {"Defines Entry"};
    const x3::rule<StatementRuleId, syntax::statements::DeclarationStatement>   declarationStatement   {"Declaration Statement"};
    const x3::rule<StatementRuleId, syntax::statements::DefinesStatement>       definesStatement       {"Defines Statement"};
    const x3::rule<StatementRuleId, syntax::statements::ImportStatement>        importStatement        {"Import Statement"};
    const x3::rule<StatementRuleId, syntax::statements::ProtocolEntry>          protocolEntry          {"Protocol Entry"};
    const x3::rule<StatementRuleId, syntax::statements::ProtocolStatement>      protocolStatement      {"Protocol Statement"};


    const auto mappingEntryProperty_def = properties::defaultProperty |
                                          properties::idProperty |
                                          properties::definitionProperty;
    const auto mappingStatementProperty_def = properties::defaultProperty |
                                              properties::finalProperty |
                                              properties::idProperty |
                                              properties::definitionProperty |
                                              properties::endianProperty;

    const auto usingStatement_def       = -keywords::variableScope >> keywords::usingKeyword > variables::identifier > '=' > variables::variableName;
    const auto headerStatement_def      = keywords::headerKeyword > variables::identifier > '{' > +variables::variableDeclaration > '}';
    const auto mappingEntry_def         = literals::literal >> -("->" >> +mappingEntryProperty);
    const auto mappingStatement_def     = keywords::mappingKeyword > variables::variableName > -("->" >> +mappingStatementProperty) > '{' > +mappingEntry > '}';
    const auto definesEntry_def         = headerStatement | mappingStatement | usingStatement;
    const auto declarationEntry_def     = requestStatement | responseStatement;
    const auto definesStatement_def     = keywords::definesKeyword >> '{' >> +definesEntry >> '}';
    const auto roundStatement_def       = keywords::roundKeyword > -variables::identifier >> symbols::openBlockBrace > variables::variableDeclaration > symbols::closeBlockBrace;
    const auto requestStatement_def     = keywords::requestKeyword >> '{' >> +roundStatement >> '}';
    const auto responseStatement_def    = keywords::responseKeyword >> '{' >> +roundStatement >> '}';
    const auto declarationStatement_def = keywords::declarationKeyword >> '{' >> +declarationEntry >> '}';
    const auto protocolEntry_def        = definesStatement | declarationStatement;
    const auto protocolStatement_def    = keywords::protocolKeyword > variables::identifier > '{' > +protocolEntry > '}';
    const auto importStatement_def      = keywords::importKeyword > variables::identifier;


    BOOST_SPIRIT_DEFINE(mappingEntryProperty);
    BOOST_SPIRIT_DEFINE(mappingStatementProperty);

    BOOST_SPIRIT_DEFINE(usingStatement);
    BOOST_SPIRIT_DEFINE(headerStatement);
    BOOST_SPIRIT_DEFINE(mappingEntry);
    BOOST_SPIRIT_DEFINE(mappingStatement);
    BOOST_SPIRIT_DEFINE(definesEntry);
    BOOST_SPIRIT_DEFINE(roundStatement);
    BOOST_SPIRIT_DEFINE(requestStatement);
    BOOST_SPIRIT_DEFINE(responseStatement);
    BOOST_SPIRIT_DEFINE(declarationEntry);
    BOOST_SPIRIT_DEFINE(definesStatement);
    BOOST_SPIRIT_DEFINE(declarationStatement);
    BOOST_SPIRIT_DEFINE(protocolEntry);
    BOOST_SPIRIT_DEFINE(protocolStatement);
    BOOST_SPIRIT_DEFINE(importStatement);

}  // namespace statements.
