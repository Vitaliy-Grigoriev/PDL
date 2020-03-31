#pragma once

#include "Methods.hpp"
#include "../syntax/Properties.hpp"


namespace pdl::spirit::grammar::properties
{
    struct PropertyRuleId : RuleId {
    };

    const x3::rule<PropertyRuleId, syntax::properties::DefaultProperty>      defaultProperty      {"Default Property"};
    const x3::rule<PropertyRuleId, syntax::properties::DefinitionProperty>   definitionProperty   {"Definition Property"};
    const x3::rule<PropertyRuleId, syntax::properties::RequiredProperty>     requiredProperty     {"Required Property"};
    const x3::rule<PropertyRuleId, syntax::properties::VolatileProperty>     volatileProperty     {"Volatile Property"};
    const x3::rule<PropertyRuleId, syntax::properties::FinalProperty>        finalProperty        {"Final Property"};
    const x3::rule<PropertyRuleId, syntax::properties::ConstProperty>        constProperty        {"Const Property"};
    const x3::rule<PropertyRuleId, syntax::properties::EndianProperty>       endianProperty       {"Endian Property"};
    const x3::rule<PropertyRuleId, syntax::properties::IdProperty>           idProperty           {"Id Property"};


    const auto defaultProperty_def    = x3::lit("default") >> -(symbols::openParamBrace >> literals::defaultValueLiteral >> symbols::closeParamBrace);
    const auto definitionProperty_def = keywords::definitionKeyword >> symbols::openParamBrace >> literals::definitionLiteral >> symbols::closeParamBrace;
    const auto requiredProperty_def   = keywords::requiredKeyword;
    const auto volatileProperty_def   = keywords::volatileKeyword;
    const auto finalProperty_def      = keywords::finalKeyword;
    const auto constProperty_def      = keywords::constKeyword;
    const auto endianProperty_def     = keywords::endianKeywords;
    const auto idProperty_def         = keywords::idKeyword > symbols::openParamBrace > literals::idLiteral > symbols::closeParamBrace > -methods::prefixMethod;


    BOOST_SPIRIT_DEFINE(defaultProperty);
    BOOST_SPIRIT_DEFINE(definitionProperty);
    BOOST_SPIRIT_DEFINE(requiredProperty);
    BOOST_SPIRIT_DEFINE(volatileProperty);
    BOOST_SPIRIT_DEFINE(finalProperty);
    BOOST_SPIRIT_DEFINE(constProperty);
    BOOST_SPIRIT_DEFINE(endianProperty);
    BOOST_SPIRIT_DEFINE(idProperty);

}  // namespace properties.
