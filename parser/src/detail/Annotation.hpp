#pragma once

#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>

#include <string>
#include <cstddef>

namespace pdl::detail::syntax
{
    namespace x3 = boost::spirit::x3;

    struct Annotation : x3::position_tagged {
        std::string input;
        std::size_t lineBegin = 0;
        std::size_t columnBegin = 0;
        std::size_t lineEnd = 0;
        std::size_t columnEnd = 0;
    };

}  // namespace syntax.
