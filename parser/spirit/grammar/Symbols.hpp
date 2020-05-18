#pragma once

#include <boost/spirit/home/x3/string/literal_string.hpp>


namespace pdl::spirit::grammar::symbols
{
    namespace x3 = boost::spirit::x3;

    const auto openSquareBrace = x3::lit('[');
    const auto closeSquareBrace = x3::lit(']');

    const auto openParamBrace = x3::lit('(');
    const auto closeParamBrace = x3::lit(')');

    const auto openBlockBrace = x3::lit('{');
    const auto closeBlockBrace = x3::lit('}');

    const auto quote = x3::lit('"');

    const auto property = x3::lit("->");

    const auto dot = x3::lit('.');
    const auto comma = x3::lit(',');
    const auto colon = x3::lit(':');
    const auto semicolon = x3::lit(';');

    const auto space = x3::lit(' ');
    const auto underline = x3::lit('_');

    const auto equality = x3::lit('=');
    const auto plus = x3::lit('+');
    const auto minus = x3::lit('-');

}  // namespace symbols.

