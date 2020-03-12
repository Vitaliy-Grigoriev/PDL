#pragma once

#define BOOST_SPIRIT_X3_UNICODE

#include "../Common.hpp"
#include "Properties.hpp"

#include <optional>

namespace pdl::detail::syntax
{
    struct MemberExpr : std::vector<Identifier>, Annotation {
    };

    struct VariableDeclaration : Annotation {
        VariableType type;
        Identifier name;
        std::optional<Literal> value;
        std::vector<VariableProperties> properties;
    };

    struct MappingEntry : Annotation {
        Literal value;
        std::vector<MappingEntryProperties> properties;
    };

    struct HeaderStatement : Annotation {
        Identifier name;
        std::vector<VariableDeclaration> fields;
    };

    struct MappingStatement : Annotation {
        MemberExpr field;
        std::vector<MappingProperties> properties;
        std::vector<MappingEntry> mapping;
    };

    struct DefinesStatements : x3::variant<HeaderStatement, MappingStatement>, Annotation
    {
        DefinesStatements & operator= (const DefinesStatements &) = default;
        DefinesStatements (const DefinesStatements &) = default;
        DefinesStatements() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct DefinesStatement : Annotation {
        std::vector<DefinesStatements> defines;
    };

    struct RoundStatement : Annotation {
        Identifier name;
        Identifier identifier;
    };

    struct RequestStatement : Annotation {
        std::vector<RoundStatement> rounds;
    };

    struct ResponseStatement : Annotation {
        std::vector<RoundStatement> rounds;
    };

    struct DeclarationStatements : x3::variant<RequestStatement, ResponseStatement>, Annotation
    {
        DeclarationStatements & operator= (const DeclarationStatements &) = default;
        DeclarationStatements (const DeclarationStatements &) = default;
        DeclarationStatements() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct DeclarationStatement : Annotation {
        std::vector<DeclarationStatements> statements;
    };

    struct ProtocolStatements : x3::variant<DefinesStatement, DeclarationStatement>, Annotation
    {
        ProtocolStatements & operator= (const ProtocolStatements &) = default;
        ProtocolStatements (const ProtocolStatements &) = default;
        ProtocolStatements() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct ProtocolStatement : Annotation
    {
        Identifier name;
        std::vector<ProtocolStatements> statements;
    };

    struct ImportStatement : public Annotation
    {
        Identifier path;
    };

    struct ScriptStatements : x3::variant<ImportStatement, ProtocolStatement>, Annotation
    {
        ScriptStatements & operator= (const ScriptStatements &) = default;
        ScriptStatements (const ScriptStatements &) = default;
        ScriptStatements() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct Script : common::ClassDeclaration<Script>, Annotation
    {
        std::vector<ScriptStatements> statements;
    };

}  // namespace syntax.

// Variables.
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::VariableDeclaration, type, name, value, properties)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::MappingEntry, value, properties)

// Script Statements.
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::RoundStatement, name, identifier)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::RequestStatement, rounds)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::ResponseStatement, rounds)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::HeaderStatement, name, fields)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::MappingStatement, field, properties, mapping)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::DeclarationStatement, statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::DefinesStatement, defines)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::ProtocolStatement, name, statements)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::ImportStatement, path)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::Script, statements)
