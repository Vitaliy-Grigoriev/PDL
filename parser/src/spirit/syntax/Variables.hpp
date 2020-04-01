#pragma once

#include "Properties.hpp"

#include <optional>


namespace pdl::spirit::syntax::variables
{
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
    };


    struct VariableListInit : Annotation<VariableListInit>
    {
        std::vector<literals::Literal> values;
    };

    struct AggregateInitialization;
    struct DesignatedInitializationValue : x3::variant<literals::Literal,
                                                       x3::forward_ast<AggregateInitialization>>,
                                           Annotation<DesignatedInitializationValue>
    {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct DesignatedInitialization : Annotation<DesignatedInitialization>
    {
        literals::DesignatorLiteral member;
        DesignatedInitializationValue value;
    };

    struct VariableDesignatedInit : Annotation<VariableDesignatedInit>
    {
        std::vector<DesignatedInitialization> values;
    };

    struct AggregateInitialization : x3::variant<VariableListInit,
                                                 VariableDesignatedInit>,
                                     Annotation<AggregateInitialization>
    {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct VariableInitialization : x3::variant<literals::Literal,
                                                AggregateInitialization>,
                                    Annotation<VariableInitialization>
    {
        using base_type::base_type;
        using base_type::operator=;
    };


    struct Variable : Annotation<Variable>
    {
        VariableDeclaration variable;
        std::optional<VariableInitialization> value;
        std::vector<VariableProperty> properties;
    };

}  // namespace variables.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::variables::VariableDeclaration,        scope, type, name)

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::variables::VariableListInit,           values)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::variables::DesignatedInitialization,   member, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::variables::VariableDesignatedInit,     values)

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::variables::Variable,                   variable, value, properties)
