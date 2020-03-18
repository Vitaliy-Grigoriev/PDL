#pragma once

#include "../Common.hpp"
#include "Properties.hpp"

#include <optional>


namespace pdl::detail::syntax
{
    struct Identifier : Annotation<Identifier> {
        std::string value;
    };

    struct MemberExpr : std::vector<Identifier>, Annotation<MemberExpr> {
    };

    struct NameValue : x3::variant<Identifier, MemberExpr>, Annotation<NameValue>
    {
        NameValue & operator= (const NameValue &) = default;
        NameValue (const NameValue &) = default;
        NameValue() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct UsingStatement : Annotation<UsingStatement>
    {
        Identifier name;
        NameValue value;
    };

    struct VariableDeclaration : Annotation<VariableDeclaration>
    {
        VariableType type;
        Identifier name;
        std::optional<Literal> value;
        std::vector<VariableProperties> properties;
    };

    struct HeaderStatement : Annotation<HeaderStatement>
    {
        Identifier name;
        std::vector<VariableDeclaration> fields;
    };

    struct MappingEntry : Annotation<MappingEntry>
    {
        Literal value;
        std::vector<MappingEntryProperties> properties;
    };

    struct MappingStatement : Annotation<MappingStatement>
    {
        NameValue field;
        std::vector<MappingProperties> properties;
        std::vector<MappingEntry> values;
    };

    struct DefinesStatements : x3::variant<UsingStatement, HeaderStatement, MappingStatement>, Annotation<DefinesStatements>
    {
        DefinesStatements & operator= (const DefinesStatements &) = default;
        DefinesStatements (const DefinesStatements &) = default;
        DefinesStatements() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct DefinesStatement : Annotation<DefinesStatement> {
        std::vector<DefinesStatements> statements;
    };

    struct RoundStatement : Annotation<RoundStatement> {
        Identifier name;
        Identifier identifier;
    };

    struct RequestStatement : Annotation<RequestStatement> {
        std::vector<RoundStatement> rounds;
    };

    struct ResponseStatement : Annotation<ResponseStatement> {
        std::vector<RoundStatement> rounds;
    };

    struct DeclarationStatements : x3::variant<RequestStatement, ResponseStatement>, Annotation<DeclarationStatements>
    {
        DeclarationStatements & operator= (const DeclarationStatements &) = default;
        DeclarationStatements (const DeclarationStatements &) = default;
        DeclarationStatements() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct DeclarationStatement : Annotation<DeclarationStatement> {
        std::vector<DeclarationStatements> statements;
    };

    struct ProtocolStatements : x3::variant<DefinesStatement, DeclarationStatement>, Annotation<ProtocolStatements>
    {
        ProtocolStatements & operator= (const ProtocolStatements &) = default;
        ProtocolStatements (const ProtocolStatements &) = default;
        ProtocolStatements() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct ProtocolStatement : Annotation<ProtocolStatement>
    {
        Identifier name;
        std::vector<ProtocolStatements> statements;
    };

    struct ImportStatement : Annotation<ImportStatement>
    {
        Identifier path;
    };

    struct ScriptStatements : x3::variant<ImportStatement, ProtocolStatement>, Annotation<ScriptStatements>
    {
        ScriptStatements & operator= (const ScriptStatements &) = default;
        ScriptStatements (const ScriptStatements &) = default;
        ScriptStatements() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct Script : common::ClassDeclaration<Script>, Annotation<Script>
    {
        std::vector<ScriptStatements> statements;
    };

}  // namespace syntax.

// Variables.
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::Identifier, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::VariableDeclaration, type, name, value, properties)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::MappingEntry, value, properties)

// Script Statements.
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::UsingStatement, name, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::RoundStatement, name, identifier)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::RequestStatement, rounds)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::ResponseStatement, rounds)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::HeaderStatement, name, fields)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::MappingStatement, field, properties, values)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::DeclarationStatement, statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::DefinesStatement, statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::ProtocolStatement, name, statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::ImportStatement, path)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::Script, statements)
