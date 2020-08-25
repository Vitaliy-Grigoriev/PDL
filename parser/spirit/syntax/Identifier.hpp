#pragma once

#include <boost/fusion/include/adapt_struct.hpp>
#include <parser/spirit/Annotation.hpp>


namespace pdl::spirit::syntax {

struct Identifier : Annotation<Identifier>
{
    std::string value;
};

}  // namespace syntax.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::Identifier,   value)
