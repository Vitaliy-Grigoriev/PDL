#pragma once

#include "../Annotation.hpp"

#include <boost/fusion/include/adapt_struct.hpp>


namespace pdl::spirit::syntax
{
    struct Identifier : Annotation<Identifier>
    {
        std::string value;
    };

}  // namespace syntax.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::Identifier,   value)
