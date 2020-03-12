#pragma once

#include "Types.hpp"
#include "Literals.hpp"


namespace pdl::detail::syntax
{
    struct DefaultProperty : Annotation {
        DefaultValueLiteral value;
    };

    struct DefinitionProperty : Annotation {
        DefinitionLiteral value;
    };

    struct RequiredProperty : Annotation {
        bool discovered = false;
    };

    struct VolatileProperty : Annotation {
        bool discovered = false;
    };

    struct FinalProperty : Annotation {
        bool discovered = false;
    };

    struct EndianProperty : Annotation {
        EndianType type = EndianType::LITTLE;
    };

    struct IdProperty : Annotation {
        IdLiteral id;
    };



    struct MappingEntryProperties : x3::variant<IdProperty, DefinitionProperty>, Annotation {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct MappingProperties : x3::variant<DefaultProperty, FinalProperty, IdProperty, DefinitionProperty, EndianProperty>, Annotation {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct VariableProperties : x3::variant<DefinitionProperty, RequiredProperty, VolatileProperty>, Annotation {
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
