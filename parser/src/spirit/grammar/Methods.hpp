#pragma once

#include "Literals.hpp"
#include "../syntax/Methods.hpp"


namespace pdl::spirit::grammar::methods
{
    struct MethodRuleId : RuleId {
    };

    const x3::rule<MethodRuleId, syntax::methods::PrefixMethod>   prefixMethod   {"Prefix Method"};

    const auto prefixMethod_def = symbols::dot > keywords::prefixKeyword > symbols::openParamBrace > literals::prefixLiteral > symbols::closeParamBrace;

    BOOST_SPIRIT_DEFINE(prefixMethod);

}  // namespace methods.
