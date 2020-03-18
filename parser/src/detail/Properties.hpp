#pragma once

#include "Types.hpp"
#include "Literals.hpp"


namespace pdl::detail::syntax
{
    struct DefaultProperty : Annotation<DefaultProperty> {
        std::optional<DefaultValueLiteral> value;
    };

    struct DefinitionProperty : Annotation<DefinitionProperty> {
        DefinitionLiteral value;
    };

    struct RequiredProperty : Annotation<RequiredProperty> {
        bool discovered = false;
    };

    struct VolatileProperty : Annotation<VolatileProperty> {
        bool discovered = false;
    };

    struct FinalProperty : Annotation<FinalProperty> {
        bool discovered = false;
    };

    struct EndianProperty : Annotation<EndianProperty> {
        EndianType type = EndianType::LITTLE;
    };

    struct IdProperty : Annotation<IdProperty> {
        IdLiteral id;
    };



    struct MappingEntryProperties : x3::variant<DefaultProperty, IdProperty, DefinitionProperty>, Annotation<MappingEntryProperties> {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct MappingProperties : x3::variant<DefaultProperty, FinalProperty, IdProperty, DefinitionProperty, EndianProperty>, Annotation<MappingProperties> {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct VariableProperties : x3::variant<DefinitionProperty, RequiredProperty, VolatileProperty>, Annotation<VariableProperties> {
        using base_type::base_type;
        using base_type::operator=;
    };

}  // namespace syntax.

BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::DefaultProperty, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::DefinitionProperty, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::RequiredProperty, discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::VolatileProperty, discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::FinalProperty, discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::EndianProperty, type)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::IdProperty, id)
