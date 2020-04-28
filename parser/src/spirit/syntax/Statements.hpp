#pragma once

#include "Variables.hpp"


namespace pdl::spirit::syntax::statements
{
    struct UsingStatement : Annotation<UsingStatement>
    {
        Identifier name;
        variables::VariableName value;
    };

    struct StructProperty : x3::variant<properties::EndianProperty,
                                        properties::IeeeProperty,
                                        properties::RfcProperty>,
                            Annotation<StructProperty>
    {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct StructStatement : Annotation<StructStatement>
    {
        Identifier name;
        std::optional<types::InternalVariableType> type;
        std::vector<StructProperty> properties;
        std::vector<variables::Variable> fields;
    };

    struct HeaderProperty : x3::variant<properties::EndianProperty,
                                        properties::IeeeProperty,
                                        properties::RfcProperty>,
                            Annotation<HeaderProperty>
    {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct HeaderStatement : Annotation<HeaderStatement>
    {
        Identifier name;
        std::vector<HeaderProperty> properties;
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

    struct DefineEntry : x3::variant<UsingStatement,
                                     StructStatement,
                                     HeaderStatement,
                                     MappingStatement>,
                          Annotation<DefineEntry>
    {
        DefineEntry & operator= (const DefineEntry &) = default;
        DefineEntry (const DefineEntry &) = default;
        DefineEntry() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct DefineStatement : Annotation<DefineStatement>
    {
        std::vector<DefineEntry> statements;
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

    struct ProtocolProperty : x3::variant<properties::RootProperty,
                                          properties::NextProtocolProperty>,
                                  Annotation<ProtocolProperty>
    {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct ProtocolEntry : x3::variant<DefineStatement,
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
        std::vector<ProtocolProperty> protocols;
        std::vector<ProtocolEntry> statements;
    };

    struct ImportStatement : Annotation<ImportStatement>
    {
        Identifier path;
    };

}  // namespace statements.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::MappingEntry,           value, properties)

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::UsingStatement,         name, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::RoundStatement,         name, statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::RequestStatement,       rounds)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::ResponseStatement,      rounds)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::StructStatement,        name, type, properties, fields)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::HeaderStatement,        name, properties, fields)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::MappingStatement,       field, properties, values)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::DeclarationStatement,   statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::DefineStatement,        statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::ProtocolStatement,      name, protocols, statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::ImportStatement,        path)
