#pragma once

#include "Literals.hpp"

#include <parser/spirit/syntax/Methods.hpp>


namespace pdl::spirit::grammar::methods {

struct MethodRuleId : RuleId {
};

constexpr x3::rule<MethodRuleId, syntax::methods::PrefixMethod>   prefixMethod   { "Prefix Method" };

const auto prefixMethod_def = symbols::dot > keywords::_prefix > utils::makeParamBraceExpect(literals::prefixLiteral);

BOOST_SPIRIT_DEFINE(prefixMethod);

}  // namespace methods.
