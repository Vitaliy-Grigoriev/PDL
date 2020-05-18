#pragma once

#include <boost/spirit/home/x3/core/call.hpp>


namespace pdl::spirit::grammar::actions
{
    auto print = [] (auto& ctx) {
        auto attr = x3::_attr(ctx).value;
        std::cout << "Action Print: " << attr << '.' << std::endl;
    };

}  // namespace actions.
