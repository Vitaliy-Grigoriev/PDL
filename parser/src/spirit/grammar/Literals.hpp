#pragma once

#include "Types.hpp"
#include "Identifier.hpp"
#include "../syntax/Literals.hpp"


namespace pdl::spirit::grammar::literals
{
    struct LiteralRuleId : RuleId {
    };

    const x3::rule<LiteralRuleId, syntax::literals::AutoLiteral>              autoLiteral          {"Auto Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::DefaultLiteral>           defaultLiteral       {"Default Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::PlaceholderLiteral, true> placeholderLiteral   {"Placeholder Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::DesignatorLiteral>        designatorLiteral    {"Designator Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::NumericLiteral>           numericLiteral       {"Numeric Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::FloatLiteral>             floatLiteral         {"Float Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::BooleanLiteral,     true> booleanLiteral       {"Boolean Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::StringLiteral>            stringLiteral        {"String Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::MacAddressLiteral>        macAddressLiteral    {"Mac Address Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::IPv4AddressLiteral>       ipv4AddressLiteral   {"IPv4 Address Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::DefinitionLiteral>        definitionLiteral    {"Definition Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::PrefixLiteral>            prefixLiteral        {"Prefix Literal"};

    const x3::rule<LiteralRuleId, syntax::literals::DefaultValueLiteral>   defaultValueLiteral   {"Default Value Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::IdLiteral>             idLiteral             {"Id Literal"};
    const x3::rule<LiteralRuleId, syntax::literals::Literal>               literal               {"Literal"};


    const auto autoLiteral_def        = keywords::autoKeyword;
    const auto defaultLiteral_def     = keywords::defaultKeyword;
    const auto placeholderLiteral_def = symbols::underline > x3::uint16;
    const auto designatorLiteral_def  = symbols::dot > identifier;
    const auto numericLiteral_def     = types::bin | types::hex | x3::int_;
    const auto floatLiteral_def       = x3::float_;
    const auto booleanLiteral_def     = keywords::booleanKeywords;
    const auto stringLiteral_def      = x3::lexeme[symbols::quote > *(x3::char_ - symbols::quote) > symbols::quote];
    const auto macAddressLiteral_def  = x3::raw[x3::repeat(5)[types::byte >> symbols::colon] >> types::byte];
    const auto ipv4AddressLiteral_def = x3::raw[x3::repeat(3)[types::octet >> symbols::dot] >> types::octet];
    const auto definitionLiteral_def  = x3::raw[x3::lexeme[x3::alpha >> *(x3::alnum | symbols::underline | symbols::space)]];
    const auto prefixLiteral_def      = x3::raw[x3::lexeme[x3::upper >> *(x3::upper | symbols::underline)] - keywords::reservedWords];

    const auto defaultValueLiteral_def = placeholderLiteral | numericLiteral | definitionLiteral;
    const auto idLiteral_def = autoLiteral | numericLiteral | definitionLiteral;
    const auto literal_def = defaultLiteral |
                             ipv4AddressLiteral |
                             macAddressLiteral |
                             numericLiteral |
                             floatLiteral |
                             booleanLiteral |
                             stringLiteral;


    BOOST_SPIRIT_DEFINE(autoLiteral);
    BOOST_SPIRIT_DEFINE(defaultLiteral);
    BOOST_SPIRIT_DEFINE(placeholderLiteral);
    BOOST_SPIRIT_DEFINE(designatorLiteral);
    BOOST_SPIRIT_DEFINE(numericLiteral);
    BOOST_SPIRIT_DEFINE(floatLiteral);
    BOOST_SPIRIT_DEFINE(booleanLiteral);
    BOOST_SPIRIT_DEFINE(stringLiteral);
    BOOST_SPIRIT_DEFINE(macAddressLiteral);
    BOOST_SPIRIT_DEFINE(ipv4AddressLiteral);
    BOOST_SPIRIT_DEFINE(definitionLiteral);
    BOOST_SPIRIT_DEFINE(prefixLiteral);

    BOOST_SPIRIT_DEFINE(defaultValueLiteral);
    BOOST_SPIRIT_DEFINE(idLiteral);
    BOOST_SPIRIT_DEFINE(literal);

}   // namespace literals.


