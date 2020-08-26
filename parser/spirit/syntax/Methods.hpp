#pragma once

#include "Literals.hpp"


namespace pdl::spirit::syntax::methods {

struct PrefixMethod : Annotation<PrefixMethod>
{
    literal::Prefix value;
};

}  // namespace methods.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::methods::PrefixMethod,   value)
