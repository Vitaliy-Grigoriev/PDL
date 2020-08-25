#pragma once

#include <boost/spirit/home/x3/string/literal_string.hpp>


namespace pdl::spirit::grammar::symbols {

constexpr auto openSquareBrace  = x3::lit('[');
constexpr auto closeSquareBrace = x3::lit(']');

constexpr auto openParamBrace  = x3::lit('(');
constexpr auto closeParamBrace = x3::lit(')');

constexpr auto openBlockBrace  = x3::lit('{');
constexpr auto closeBlockBrace = x3::lit('}');

constexpr auto quote = x3::lit('"');

constexpr auto property = x3::lit("->");

constexpr auto dot       = x3::lit('.');
constexpr auto comma     = x3::lit(',');
constexpr auto colon     = x3::lit(':');
constexpr auto semicolon = x3::lit(';');

constexpr auto space     = x3::lit(' ');
constexpr auto underline = x3::lit('_');

constexpr auto equality       = x3::lit('=');
constexpr auto plus           = x3::lit('+');
constexpr auto minus          = x3::lit('-');
constexpr auto multiplication = x3::lit('*');
constexpr auto division       = x3::lit('/');

constexpr auto slash     = division;
constexpr auto backslash = x3::lit('\\');

}  // namespace symbols.
