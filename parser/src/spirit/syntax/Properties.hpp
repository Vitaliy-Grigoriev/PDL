#pragma once

#include "Types.hpp"
#include "Methods.hpp"


namespace pdl::spirit::syntax::properties
{
    struct DefaultProperty : Annotation<DefaultProperty>
    {
        std::optional<literals::DefaultValueLiteral> value;
    };

    struct DefinitionProperty : Annotation<DefinitionProperty>
    {
        literals::DefinitionLiteral value;
    };

    struct RequiredProperty : Annotation<RequiredProperty>
    {
        bool discovered = false;
    };

    struct VolatileProperty : Annotation<VolatileProperty>
    {
        bool discovered = false;
    };

    struct FinalProperty : Annotation<FinalProperty>
    {
        bool discovered = false;
    };

    struct ConstProperty : Annotation<ConstProperty>
    {
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

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::DefaultProperty,    value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::DefinitionProperty, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::RequiredProperty,   discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::VolatileProperty,   discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::FinalProperty,      discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::ConstProperty,      discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::EndianProperty,     type)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::properties::IdProperty,         id, prefix)
