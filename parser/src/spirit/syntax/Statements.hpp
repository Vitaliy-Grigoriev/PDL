#pragma once

#include "Variables.hpp"


namespace pdl::spirit::syntax::statements
{
    struct UsingStatement : Annotation<UsingStatement>
    {
        types::VariableScope scope = types::VariableScope::LOCAL;
        Identifier name;
        variables::VariableName value;
    };

    struct HeaderStatement : Annotation<HeaderStatement>
    {
        Identifier name;
        std::vector<variables::Variable> fields;
    };

    struct MappingEntryProperty : x3::variant<properties::DefaultProperty,
                                              properties::IdProperty,
                                              properties::DefinitionProperty>,
                                  Annotation<MappingEntryProperty>
    {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct MappingEntry : Annotation<MappingEntry>
    {
        literals::Literal value;
        std::vector<MappingEntryProperty> properties;
    };

    struct MappingStatementProperty : x3::variant<properties::DefaultProperty,
                                                  properties::FinalProperty,
                                                  properties::IdProperty,
                                                  properties::DefinitionProperty,
                                                  properties::EndianProperty>,
                             Annotation<MappingStatementProperty>
    {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct MappingStatement : Annotation<MappingStatement>
    {
        variables::VariableName field;
        std::vector<MappingStatementProperty> properties;
        std::vector<MappingEntry> values;
    };

    struct DefinesEntry : x3::variant<UsingStatement,
                                      HeaderStatement,
                                      MappingStatement>,
                          Annotation<DefinesEntry>
    {
        DefinesEntry & operator= (const DefinesEntry &) = default;
        DefinesEntry (const DefinesEntry &) = default;
        DefinesEntry() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct DefinesStatement : Annotation<DefinesStatement>
    {
        std::vector<DefinesEntry> statements;
    };

    struct RoundStatement : Annotation<RoundStatement>
    {
        Identifier name;
        std::vector<variables::Variable> statements;
    };

    struct RequestStatement : Annotation<RequestStatement>
    {
        std::vector<RoundStatement> rounds;
    };

    struct ResponseStatement : Annotation<ResponseStatement>
    {
        std::vector<RoundStatement> rounds;
    };

    struct DeclarationEntry : x3::variant<RequestStatement,
                                          ResponseStatement>,
                              Annotation<DeclarationEntry>
    {
        DeclarationEntry & operator= (const DeclarationEntry &) = default;
        DeclarationEntry (const DeclarationEntry &) = default;
        DeclarationEntry() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct DeclarationStatement : Annotation<DeclarationStatement>
    {
        std::vector<DeclarationEntry> statements;
    };

    struct ProtocolEntry : x3::variant<DefinesStatement,
                                       DeclarationStatement>,
                           Annotation<ProtocolEntry>
    {
        ProtocolEntry & operator= (const ProtocolEntry &) = default;
        ProtocolEntry (const ProtocolEntry &) = default;
        ProtocolEntry() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct ProtocolStatement : Annotation<ProtocolStatement>
    {
        Identifier name;
        std::vector<ProtocolEntry> statements;
    };

    struct ImportStatement : Annotation<ImportStatement>
    {
        Identifier path;
    };

}  // namespace statements.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::MappingEntry,           value, properties)

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::UsingStatement,         scope, name, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::RoundStatement,         name, statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::RequestStatement,       rounds)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::ResponseStatement,      rounds)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::HeaderStatement,        name, fields)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::MappingStatement,       field, properties, values)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::DeclarationStatement,   statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::DefinesStatement,       statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::ProtocolStatement,      name, statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::ImportStatement,        path)
