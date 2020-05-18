#pragma once

#include "Types.hpp"
#include "Methods.hpp"


namespace pdl::spirit::syntax::properties
{
    struct RootProperty : Annotation<RootProperty>
    {
        [[maybe_unused]]
        bool discovered = false;
    };

    struct NextProtocolProperty : Annotation<NextProtocolProperty>
    {
        std::vector<Identifier> protocols;
    };

    struct DefaultProperty : Annotation<DefaultProperty>
    {
        std::optional<literals::DefaultValueLiteral> value;
    };

    struct DefinitionProperty : Annotation<DefinitionProperty>
    {
        literals::DefinitionLiteral value;
    };

    struct PriorityProperty : Annotation<PriorityProperty>
    {
        uint16_t value = 0;
    };

    struct IeeeProperty : Annotation<IeeeProperty>
    {
        literals::DefinitionLiteral ieee;
    };

    struct RfcProperty : Annotation<RfcProperty>
    {
        uint16_t rfc = 0;
        literals::DefinitionLiteral section;
    };

    struct RequiredProperty : Annotation<RequiredProperty>
    {
        [[maybe_unused]]
        bool discovered = false;
    };

    struct VariableProperty : Annotation<VariableProperty>
    {
        [[maybe_unused]]
        bool discovered = false;
    };

    struct FinalProperty : Annotation<FinalProperty>
    {
        [[maybe_unused]]
        bool discovered = false;
    };

    struct ConstProperty : Annotation<ConstProperty>
    {
        [[maybe_unused]]
        bool discovered = false;
    };

    struct CalculatedProperty : Annotation<CalculatedProperty>
    {
        [[maybe_unused]]
        bool discovered = false;
    };

    struct EndianProperty : Annotation<EndianProperty>
    {
        types::EndianType type = types::EndianType::LITTLE;
    };

    struct IdProperty : Annotation<IdProperty>
    {
        literals::IdLiteral id;
        methods::PrefixMethod prefix;
    };

}  // namespace properties.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::RootProperty,           discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::NextProtocolProperty,   protocols)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::DefaultProperty,        value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::DefinitionProperty,     value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::PriorityProperty,       value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::IeeeProperty,           ieee)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::RfcProperty,            rfc, section)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::RequiredProperty,       discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::VariableProperty,       discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::FinalProperty,          discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::ConstProperty,          discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::CalculatedProperty,     discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::EndianProperty,         type)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::IdProperty,             id, prefix)
