#pragma once

#include "Utils.hpp"
#include "Handlers.hpp"

#include <parser/spirit/syntax/Identifier.hpp>


namespace pdl::spirit::grammar {

constexpr x3::rule<RuleId, syntax::Identifier>   identifier   { "Identifier" };

const auto identifier_def = x3::raw[x3::lexeme[(x3::alnum) >> *(x3::alnum | symbols::underline)] - keywords::reservedWords];

BOOST_SPIRIT_DEFINE(identifier);

}  // namespace grammar.
