#pragma once

#include "Groups.hpp"


namespace pdl::spirit::syntax::statements {

struct UsingStatement : Annotation<UsingStatement>
{
    Identifier name;
    variables::VariableName value;
};

struct HeaderProperty : x3::variant<properties::EndianProperty,
                                    properties::IeeeProperty,
                                    properties::RfcProperty,
                                    properties::DefinitionProperty>,
                        Annotation<HeaderProperty>
{
    using base_type::base_type;
    using base_type::operator=;
};

struct StructStatement : Annotation<StructStatement>
{
    Identifier name;
    std::optional<types::InternalVariableType> type;
    std::vector<HeaderProperty> properties;
    std::vector<variables::Variable> fields;
};

struct HeaderEntry : x3::variant<groups::StaticGroup,
                                 groups::ConditionalGroup,
                                 groups::OptionalGroup>,
                     Annotation<HeaderEntry>
{
    using base_type::base_type;
    using base_type::operator=;
};

struct HeaderStatement : Annotation<HeaderStatement>
{
    Identifier name;
    std::vector<HeaderProperty> properties;
    std::vector<HeaderEntry> groups;
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

struct StructureEntry : x3::variant<UsingStatement,
                                    StructStatement,
                                    HeaderStatement,
                                    MappingStatement>,
                        Annotation<StructureEntry>
{
    using base_type::base_type;
    using base_type::operator=;
};

struct StructureStatement : Annotation<StructureStatement>
{
    std::vector<StructureEntry> statements;
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

struct ProtocolEntry : x3::variant<StructureStatement,
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
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::HeaderStatement,        name, properties, groups)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::MappingStatement,       field, properties, values)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::DeclarationStatement,   statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::StructureStatement,     statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::ProtocolStatement,      name, protocols, statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::statements::ImportStatement,        path)
