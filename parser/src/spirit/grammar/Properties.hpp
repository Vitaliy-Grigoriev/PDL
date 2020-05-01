#pragma once

#include "Methods.hpp"
#include "../syntax/Properties.hpp"


namespace pdl::spirit::grammar::properties
{
    struct PropertyRuleId : RuleId {
    };

    const x3::rule<PropertyRuleId, syntax::properties::RootProperty>           rootProperty           {"Root Property"};
    const x3::rule<PropertyRuleId, syntax::properties::NextProtocolProperty>   nextProtocolProperty   {"Next Protocol Property"};
    const x3::rule<PropertyRuleId, syntax::properties::DefaultProperty>        defaultProperty        {"Default Property"};
    const x3::rule<PropertyRuleId, syntax::properties::DefinitionProperty>     definitionProperty     {"Definition Property"};
    const x3::rule<PropertyRuleId, syntax::properties::PriorityProperty>       priorityProperty       {"Priority Property"};
    const x3::rule<PropertyRuleId, syntax::properties::IeeeProperty>           ieeeProperty           {"IEEE Property"};
    const x3::rule<PropertyRuleId, syntax::properties::RfcProperty>            rfcProperty            {"RFC Property"};
    const x3::rule<PropertyRuleId, syntax::properties::RequiredProperty>       requiredProperty       {"Required Property"};
    const x3::rule<PropertyRuleId, syntax::properties::VariableProperty>       variableProperty       {"Variable Property"};
    const x3::rule<PropertyRuleId, syntax::properties::FinalProperty>          finalProperty          {"Final Property"};
    const x3::rule<PropertyRuleId, syntax::properties::ConstProperty>          constProperty          {"Const Property"};
    const x3::rule<PropertyRuleId, syntax::properties::CalculatedProperty>     calculatedProperty     {"Calculated Property"};
    const x3::rule<PropertyRuleId, syntax::properties::EndianProperty>         endianProperty         {"Endian Property"};
    const x3::rule<PropertyRuleId, syntax::properties::IdProperty>             idProperty             {"Id Property"};

    const auto rootProperty_def         = keywords::_root;
    const auto nextProtocolProperty_def = keywords::_nextProtocol > utils::makeSquareBrace(identifier % symbols::comma);
    const auto defaultProperty_def      = x3::lit("default") >> -(symbols::openParamBrace >> literals::defaultValueLiteral >> symbols::closeParamBrace);
    const auto definitionProperty_def   = keywords::_definition >> symbols::openParamBrace >> literals::definitionLiteral >> symbols::closeParamBrace;
    const auto priorityProperty_def     = keywords::_priority > symbols::openParamBrace > x3::uint16 > symbols::closeParamBrace;
    const auto ieeeProperty_def         = keywords::_ieee > symbols::openParamBrace > literals::definitionLiteral > symbols::closeParamBrace;
    const auto rfcProperty_def          = keywords::_rfc > symbols::openParamBrace > x3::uint16 > -(x3::lit("/") > literals::definitionLiteral) > symbols::closeParamBrace;
    const auto requiredProperty_def     = keywords::_required;
    const auto variableProperty_def     = keywords::_variable;
    const auto finalProperty_def        = keywords::_final;
    const auto constProperty_def        = keywords::_const;
    const auto calculatedProperty_def   = keywords::_calculated;
    const auto endianProperty_def       = keywords::_endian;
    const auto idProperty_def           = keywords::_id > symbols::openParamBrace > literals::idLiteral > symbols::closeParamBrace > -methods::prefixMethod;


    BOOST_SPIRIT_DEFINE(rootProperty);
    BOOST_SPIRIT_DEFINE(nextProtocolProperty);
    BOOST_SPIRIT_DEFINE(defaultProperty);
    BOOST_SPIRIT_DEFINE(definitionProperty);
    BOOST_SPIRIT_DEFINE(priorityProperty);
    BOOST_SPIRIT_DEFINE(ieeeProperty);
    BOOST_SPIRIT_DEFINE(rfcProperty);
    BOOST_SPIRIT_DEFINE(requiredProperty);
    BOOST_SPIRIT_DEFINE(variableProperty);
    BOOST_SPIRIT_DEFINE(finalProperty);
    BOOST_SPIRIT_DEFINE(constProperty);
    BOOST_SPIRIT_DEFINE(calculatedProperty);
    BOOST_SPIRIT_DEFINE(endianProperty);
    BOOST_SPIRIT_DEFINE(idProperty);

}  // namespace properties.
