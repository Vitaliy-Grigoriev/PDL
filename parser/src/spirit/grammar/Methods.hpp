#pragma once

#include "Literals.hpp"
#include "../syntax/Methods.hpp"


namespace pdl::spirit::grammar::methods
{

struct MethodRuleId : RuleId {
};

const x3::rule<MethodRuleId, syntax::methods::PrefixMethod>   prefixMethod   {"Prefix Method"};

const auto prefixMethod_def = symbols::dot > keywords::_prefix > utils::makeParamBrace(literals::prefixLiteral);

BOOST_SPIRIT_DEFINE(prefixMethod);

}  // namespace methods.
