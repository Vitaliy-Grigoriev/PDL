#pragma once

#include "Properties.hpp"

#include <optional>


namespace pdl::spirit::syntax::variables
{
    struct Identifier : Annotation<Identifier>
    {
        std::string value;
    };

    struct VariableType : x3::variant<types::InternalVariableType,
                                      Identifier>,
                          Annotation<VariableType>
    {
        VariableType & operator= (const VariableType &) = default;
        VariableType (const VariableType &) = default;
        VariableType() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct MemberVariable : std::vector<Identifier>,
                            Annotation<MemberVariable>
    { };

    struct VariableName : x3::variant<Identifier,
                                      MemberVariable>,
                          Annotation<VariableName>
    {
        VariableName & operator= (const VariableName &) = default;
        VariableName (const VariableName &) = default;
        VariableName() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct VariableProperty : x3::variant<properties::DefinitionProperty,
                                          properties::RequiredProperty,
                                          properties::VolatileProperty,
                                          properties::ConstProperty>,
                              Annotation<VariableProperty>
    {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct VariableDeclaration : Annotation<VariableDeclaration>
    {
        types::VariableScope scope = types::VariableScope::LOCAL;
        VariableType type;
        Identifier name;
        std::optional<literals::Literal> value;
        std::vector<VariableProperty> properties;
    };

}  // namespace variables.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::variables::Identifier,            value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::variables::VariableDeclaration,   scope, type, name, value, properties)
